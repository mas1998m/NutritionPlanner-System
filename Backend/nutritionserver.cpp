#include "nutritionserver.h"

NutritionServer::NutritionServer(QObject* parent)
    : QObject(parent), threadPool(QThreadPool::globalInstance()), server(this),
      patientService{createBMIStrategy(loadConfiguration()),createBMRStrategy(loadConfiguration())} {


    server.route("/submitPatientInfo", [this](const QHttpServerRequest &request) {
        return QtConcurrent::run(threadPool, [this,&request]() mutable {

            if (request.method() ==  QHttpServerRequest::Method::Options){
                QHttpServerResponse response(QByteArray("application/json"),QHttpServerResponse::StatusCode::Ok);
                response.setHeader("Access-Control-Allow-Origin", "*");
                response.setHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
                response.setHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
                return response;
            }else if(request.method() == QHttpServerRequest::Method::Post){
                QJsonDocument jsonDoc = QJsonDocument::fromJson(request.body());
                QJsonObject jsonObj = jsonDoc.object();
                patients.append(jsonObj);
                patientService.calculateMetrics(patients.last());

                DietPlan plan =  dietPlanService.generateDietPlan();

                QJsonObject jsonPlan = plan.toJson();
                QJsonArray jsonNutritionSummary = plan.analyzePlanToJson();

                // Combine both into one JSON document
                QJsonObject jsonResponse;
                jsonResponse["plan"] = jsonPlan;
                jsonResponse["nutritionSummary"] = jsonNutritionSummary;
                jsonResponse["name"] = patients.last().getName();
                jsonResponse["age"] = patients.last().getAge();
                jsonResponse["height"] = patients.last().getHeight();
                jsonResponse["weight"] = patients.last().getWeight();
                jsonResponse["BMR"] = patients.last().getBMR();
                jsonResponse["BMI"] = patients.last().getBMI();
                jsonResponse["lowIdeal"] = patients.last().getIdealWeight().first;
                jsonResponse["highIdeal"] = patients.last().getIdealWeight().second;
                jsonResponse["waterIntake"] = patients.last().getIdealWaterIntake();


                emit newRequestReceived(jsonResponse);
                emit logNewRequest(jsonResponse);


                QJsonDocument resjsonDoc(jsonResponse);
                QByteArray jsonByteArray = resjsonDoc.toJson();
                QHttpServerResponse response(QByteArray("application/json"),jsonByteArray,QHttpServerResponse::StatusCode::Ok);
                response.setHeader("Access-Control-Allow-Origin", "*");
                response.setHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
                response.setHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
                return response;
            }else{
                QHttpServerResponse response(QHttpServerResponder::StatusCode::NotFound);
                return response;
            }
        });
    });

    server.route("/feedback", [this](const QHttpServerRequest &request) {
        return QtConcurrent::run(threadPool, [this,&request]() mutable {

            if (request.method() ==  QHttpServerRequest::Method::Options){
                QHttpServerResponse response(QByteArray("application/json"),QHttpServerResponse::StatusCode::Ok);
                response.setHeader("Access-Control-Allow-Origin", "*");
                response.setHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
                response.setHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
                return response;
            }else if(request.method() == QHttpServerRequest::Method::Post){
                QJsonDocument jsonDoc = QJsonDocument::fromJson(request.body());
                QJsonObject jsonObj = jsonDoc.object();
                QString feedback = jsonObj["feedback"].toString();

                QJsonObject jsonResponse;
                jsonResponse["response"] = "feedback got received";

                emit logNewFeedback(jsonObj);


                QJsonDocument resjsonDoc(jsonResponse);
                QByteArray jsonByteArray = resjsonDoc.toJson();
                QHttpServerResponse response(QByteArray("application/json"),jsonByteArray,QHttpServerResponse::StatusCode::Ok);
                response.setHeader("Access-Control-Allow-Origin", "*");
                response.setHeader("Access-Control-Allow-Methods", "GET, POST, OPTIONS");
                response.setHeader("Access-Control-Allow-Headers", "Content-Type, Authorization");
                return response;
            }else{
                QHttpServerResponse response(QHttpServerResponder::StatusCode::NotFound);
                return response;
            }
        });

    });
}

NutritionServer::~NutritionServer() {
    // server.close();
}

void NutritionServer::startServer(quint16 port) {
    server.listen(QHostAddress::Any, port);
    qDebug() << "Server started on port" << port;
}

QJsonObject NutritionServer::loadConfiguration()
{
    // Load the configuration file (e.g., config.json)
    QFile configFile("config.json");
    if (!configFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning("Couldn't open config file.");
        return QJsonObject();  // Return an empty QJsonObject if the file couldn't be opened
    }

    QJsonDocument configDoc = QJsonDocument::fromJson(configFile.readAll());
    QJsonObject configObj = configDoc.object();

    return configObj;  // Return the strategy type
}

QScopedPointer<BMI_Calculator> NutritionServer::createBMIStrategy(const QJsonObject& configObj) {
    QString strategyType = configObj["bmiStrategy"].toString();
    if (strategyType == "Metric") {
        return QScopedPointer<BMI_Calculator>(new MetricBMIStrategy());
    } else if (strategyType == "Imperial") {
        return QScopedPointer<BMI_Calculator>(new ImperialBMIStrategy());
    } else {
        qWarning("Unknown BMI strategy type. Defaulting to Metric strategy.");
        return QScopedPointer<BMI_Calculator>(new MetricBMIStrategy());
    }
}

QScopedPointer<BMR_Calculator> NutritionServer::createBMRStrategy(const QJsonObject& configObj) {
    QString strategyType = configObj["bmrStrategy"].toString();
    if (strategyType == "HarrisBenedict") {
        return QScopedPointer<BMR_Calculator>(new HarrisBenedictBMRStrategy());
    } else if (strategyType == "MifflinStJeor") {
        return QScopedPointer<BMR_Calculator>(new MifflinStJeorBMRStrategy());
    } else {
        qWarning("Unknown BMR strategy type. Defaulting to Harris-Benedict strategy.");
        return QScopedPointer<BMR_Calculator>(new HarrisBenedictBMRStrategy());
    }
}

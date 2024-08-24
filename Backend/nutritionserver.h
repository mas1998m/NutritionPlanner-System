#ifndef NUTRITIONSERVER_H
#define NUTRITIONSERVER_H


#include <QHttpServer>
#include <QJsonObject>
#include <QJsonDocument>
#include <QString>
#include <QHttpServerRequest>
#include <QHttpServerResponse>
#include <QObject>
#include <QThreadPool>
#include <QtConcurrent>
#include <QList>
#include "patient.h"
#include "patient_service.h"
#include "imperial_bmi_strategy.h"
#include "metric_bmi_strategy.h"
#include "harrisbenedict_bmr_strategy.h"
#include "mifflinstjeor_bmr_strategy.h"
#include "diet_plan_service.h"

class NutritionServer: public QObject{
    Q_OBJECT

public:
    QHttpServer server;
    NutritionServer(QObject* parent=nullptr);
    ~NutritionServer();
    void startServer(quint16 port);

signals:
    void newRequestReceived(const QJsonObject& patientInfo);
    void logNewRequest(const QJsonObject& requestInfo);
    void logNewFeedback(const QJsonObject& feedbackInfo);

private:

    QThreadPool* threadPool;
    QList<Patient> patients;
    PatientService patientService;
    DietPlanService dietPlanService;
    QJsonObject foodCategories;


    QJsonObject loadConfiguration();
    QScopedPointer<BMI_Calculator> createBMIStrategy(const QJsonObject& strategyType);
    QScopedPointer<BMR_Calculator> createBMRStrategy(const QJsonObject& strategyType);

    QString generateDietPlan(const QJsonObject &patientInfo);

};
#endif // NUTRITIONSERVER_H

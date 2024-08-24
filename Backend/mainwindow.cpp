#include "mainwindow.h"
#include "ui_mainwindow.h"
// solve this previous include please

#include <QJsonObject>
#include <QJsonDocument>
#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , totalRequests(0), totalBMI(0.0), totalBMR(0.0)
{
    ui->setupUi(this);


    QRect screenGeometry = QGuiApplication::primaryScreen()->geometry();
    int x = (screenGeometry.width() - width()) / 2;
    int y = (screenGeometry.height() - height()) / 2;
    move(x, y);

    ui->logTabs->setTabText(0,"Patients Logs");
    ui->logTabs->setTabText(1,"Feedback Logs");

    patientsHighlighter = new JsonHighlighter(ui->PatientsTextBrowser->document());
    feedbacksHighlighter = new JsonHighlighter(ui->FeedbacksTextBrowser->document());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateLastRequest(const QJsonObject& patientInfo)
{
    QString info = QString("Name: %1\nAge: %2\nHeight: %3\nWeight: %4\nBMI: %5\nBMR: %6")
                        .arg(patientInfo["name"].toString())
                        .arg(patientInfo["age"].toInt())
                        .arg(patientInfo["height"].toDouble())
                        .arg(patientInfo["weight"].toDouble())
                        .arg(patientInfo["BMI"].toDouble())
                        .arg(patientInfo["BMR"].toDouble());

    ui->lastRequestTextBrowser->setPlainText(info);

    // Update statistics
    totalRequests++;
    totalBMI += patientInfo["BMI"].toDouble();
    totalBMR += patientInfo["BMR"].toDouble();
    updateStatistics();
}

void MainWindow::updateStatistics()
{
    ui->totalRequestsLabel->setText(QString::number(totalRequests));
    ui->averageBMILabel->setText(QString::number(totalRequests > 0 ? totalBMI / totalRequests : 0.0));
    ui->averageBMRLabel->setText(QString::number(totalRequests > 0 ? totalBMR / totalRequests : 0.0));
}

void MainWindow::logRequest(const QJsonObject& requestInfo)
{
    loggedRequests.append(requestInfo);

    QFile file("requests_log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << QJsonDocument(requestInfo).toJson() << "\n";
        file.close();
    }

    // Update the log display in the UI
    QString log = ui->PatientsTextBrowser->toPlainText();
    log += QJsonDocument(requestInfo).toJson(QJsonDocument::Indented) + "\n\n";
    ui->PatientsTextBrowser->setPlainText(log);
}


void MainWindow::logFeedback(const QJsonObject& FeedbackInfo)
{

    totalFeedbacks++;
    ui->totalFeedbacksLabel->setText(QString::number(totalFeedbacks));

    loggedFeedbacks.append(FeedbackInfo);

    QFile file("feedbacks_log.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << QJsonDocument(FeedbackInfo).toJson() << "\n";
        file.close();
    }

    // Update the log display in the UI
    QString log = ui->FeedbacksTextBrowser->toPlainText();
    log += QJsonDocument(FeedbackInfo).toJson(QJsonDocument::Indented) + "\n\n";
    ui->FeedbacksTextBrowser->setPlainText(log);
}


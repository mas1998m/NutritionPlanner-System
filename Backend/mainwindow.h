#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QJsonObject>
#include "json_highlighter.h"
#include "system_monitor_widget.h"
#include <QScreen>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void updateLastRequest(const QJsonObject& patientInfo);
    void updateStatistics();
    void logRequest(const QJsonObject& requestInfo);
    void logFeedback(const QJsonObject& feedbackInfo);

private:
    Ui::MainWindow *ui;
    JsonHighlighter *patientsHighlighter;
    JsonHighlighter *feedbacksHighlighter;

    // For statistics
    int totalRequests;
    int totalFeedbacks;
    float totalBMI;
    float totalBMR;
    QList<QJsonObject> loggedRequests;
    QList<QJsonObject> loggedFeedbacks;

};

#endif // MAINWINDOW_H

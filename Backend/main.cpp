#include "mainwindow.h"

#include "nutritionserver.h"
#include <QCoreApplication>
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    NutritionServer server;

    QObject::connect(&server, &NutritionServer::newRequestReceived, &mainWindow, &MainWindow::updateLastRequest);
    QObject::connect(&server, &NutritionServer::logNewRequest, &mainWindow, &MainWindow::logRequest);
    QObject::connect(&server, &NutritionServer::logNewFeedback, &mainWindow, &MainWindow::logFeedback);

    server.startServer(8080);
    mainWindow.show();
    return app.exec();
}

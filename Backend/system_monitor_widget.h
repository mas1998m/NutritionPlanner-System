#ifndef SYSTEM_MONITOR_WIDGET_H
#define SYSTEM_MONITOR_WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QTimer>
#include <QProgressBar>
#include <sys/statvfs.h>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sstream>
#include <QStringList>


class SystemMonitorWidget : public QWidget
{
    Q_OBJECT
public:
    SystemMonitorWidget(QWidget *parent = nullptr);
    ~SystemMonitorWidget();

private slots:
    void updateSystemStatus();

private:
    QLabel *cpuLabel;
    QLabel *memoryLabel;
    QProgressBar *cpuProgressBar;
    QProgressBar *memoryProgressBar;
    QTimer *updateTimer;
    QStringList redShades;

    // Functions to get system metrics
    double getCpuUsage();
    double getMemoryUsage();
    QString getColorForUsage(double usage);

};

#endif // SYSTEM_MONITOR_WIDGET_H

#include "system_monitor_widget.h"

SystemMonitorWidget::SystemMonitorWidget(QWidget *parent)
    : QWidget(parent),
      cpuLabel(new QLabel("CPU Usage:", this)),
      memoryLabel(new QLabel("Memory Usage:", this)),
      cpuProgressBar(new QProgressBar(this)),
      memoryProgressBar(new QProgressBar(this)),
      updateTimer(new QTimer(this))
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(cpuLabel);
    layout->addWidget(cpuProgressBar);
    layout->addWidget(memoryLabel);
    layout->addWidget(memoryProgressBar);
    setLayout(layout);

    redShades = {
        "#ffcccc", // 0-10% light red
        "#ff9999", // 10-20%
        "#ff6666", // 20-30%
        "#ff3333", // 30-40%
        "#ff0000", // 40-50%
        "#cc0000", // 50-60%
        "#990000", // 60-70%
        "#660000", // 70-80%
        "#330000", // 80-90%
        "#190000"  // 90-100% dark red
    };


    // Set progress bar ranges
    cpuProgressBar->setRange(0, 100);
    memoryProgressBar->setRange(0, 100);

    // Connect the timer to the update slot
    connect(updateTimer, &QTimer::timeout, this, &SystemMonitorWidget::updateSystemStatus);
    updateTimer->start(1000);  // Update every second
}

SystemMonitorWidget::~SystemMonitorWidget() {}

QString SystemMonitorWidget::getColorForUsage(double usage) {
    int index = static_cast<int>(usage / 10); // Calculate the index (0-9)
    if (index >= 0 && index < redShades.size()) {
        return redShades[index];
    }
    return "#ff0000"; // Default color (full red) in case of any issue
}



void SystemMonitorWidget::updateSystemStatus() {
    double cpuUsage = getCpuUsage();
    double memoryUsage = getMemoryUsage();

    QString cpuColor = getColorForUsage(cpuUsage);
    QString memoryColor = getColorForUsage(memoryUsage);

    QPalette cpuPalette = cpuProgressBar->palette();
    QPalette memoryPalette = memoryProgressBar->palette();

    cpuPalette.setColor(QPalette::Highlight, QColor(cpuColor));
    memoryPalette.setColor(QPalette::Highlight, QColor(memoryColor));

    cpuProgressBar->setPalette(cpuPalette);
    memoryProgressBar->setPalette(memoryPalette);

    cpuLabel->setText(QString("CPU Usage: %1%").arg(cpuUsage));
    memoryLabel->setText(QString("Memory Usage: %1%").arg(memoryUsage));

    cpuProgressBar->setValue(static_cast<int>(cpuUsage));
    memoryProgressBar->setValue(static_cast<int>(memoryUsage));
}

double SystemMonitorWidget::getCpuUsage() {
    static long prevIdleTime = 0, prevTotalTime = 0;
    long idleTime, totalTime;

    std::ifstream file("/proc/stat");
    std::string line;
    std::getline(file, line);
    file.close();

    std::istringstream ss(line);
    std::string cpu;
    long user, nice, system, idle, iowait, irq, softirq, steal;
    ss >> cpu >> user >> nice >> system >> idle >> iowait >> irq >> softirq >> steal;

    idleTime = idle + iowait;
    totalTime = user + nice + system + idle + iowait + irq + softirq + steal;

    double cpuUsage = (1.0 - (double)(idleTime - prevIdleTime) / (totalTime - prevTotalTime)) * 100.0;

    prevIdleTime = idleTime;
    prevTotalTime = totalTime;

    return cpuUsage;
}

double SystemMonitorWidget::getMemoryUsage() {
    std::ifstream file("/proc/meminfo");
    std::string line;
    long totalMemory = 0, freeMemory = 0, buffers = 0, cached = 0;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string key;
        long value;
        std::string unit;
        ss >> key >> value >> unit;

        if (key == "MemTotal:") {
            totalMemory = value;
        } else if (key == "MemFree:") {
            freeMemory = value;
        } else if (key == "Buffers:") {
            buffers = value;
        } else if (key == "Cached:") {
            cached = value;
        }
    }
    file.close();

    long usedMemory = totalMemory - freeMemory - buffers - cached;
    return (double)usedMemory / totalMemory * 100.0;
}

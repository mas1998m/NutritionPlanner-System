#include "metric_bmi_strategy.h"

MetricBMIStrategy::MetricBMIStrategy()
{

}

double MetricBMIStrategy::calculateBMI(Patient & patient) const {
    patient.setBMI( 100 * 100 * patient.getWeight() / (patient.getHeight() * patient.getHeight()) );
    return (patient.getBMI());
}

QString MetricBMIStrategy::getDescription() const {
    return "Metric System (kg/m^2)";
}

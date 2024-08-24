#include "imperial_bmi_strategy.h"

ImperialBMIStrategy::ImperialBMIStrategy()
{

}

double ImperialBMIStrategy::calculateBMI( Patient & patient) const {
    patient.setBMI( patient.getWeight() / (patient.getHeight() * patient.getHeight()) * 703 );
    return (patient.getBMI());
}

QString ImperialBMIStrategy::getDescription() const {
    return "Imperial System (lb/in^2)";
}

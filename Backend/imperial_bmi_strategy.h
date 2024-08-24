#ifndef IMPERIAL_BMI_STRATEGY_H
#define IMPERIAL_BMI_STRATEGY_H

#include "bmi_calculator.h"

class ImperialBMIStrategy : public BMI_Calculator
{
public:
    ImperialBMIStrategy();
    double calculateBMI(Patient & patient) const override;
    QString getDescription() const override;
};

#endif // IMPERIAL_BMI_STRATEGY_H

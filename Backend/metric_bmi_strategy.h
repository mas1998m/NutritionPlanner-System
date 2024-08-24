#ifndef METRIC_BMI_STRATEGY_H
#define METRIC_BMI_STRATEGY_H

#include "bmi_calculator.h"

class MetricBMIStrategy : public BMI_Calculator
{

public:
    MetricBMIStrategy();
    double calculateBMI(Patient & patient) const override;
    QString getDescription() const override;

};

#endif // METRIC_BMI_STRATEGY_H

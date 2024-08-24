#ifndef BMR_CALCULATOR_H
#define BMR_CALCULATOR_H

#include "patient.h"
#include <QString>

class BMR_Calculator
{
public:
    BMR_Calculator();
    virtual ~BMR_Calculator();
    virtual double calculateBMR(Patient & patient) const = 0;
    virtual QString getDescription() const = 0;
    float calculateActivityFactor(const QString& activityLevel) const;
};

#endif // BMR_CALCULATOR_H

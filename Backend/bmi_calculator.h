#ifndef BMI_CALCULATOR_H
#define BMI_CALCULATOR_H

#include "patient.h"
#include <QString>

class BMI_Calculator
{
public:
    BMI_Calculator();
    virtual ~BMI_Calculator();
    virtual double calculateBMI(Patient & patient) const = 0;
    virtual QString getDescription() const = 0;
};

#endif // BMI_CALCULATOR_H

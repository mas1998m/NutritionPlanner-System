#ifndef PATIENT_SERVICE_H
#define PATIENT_SERVICE_H


#include <QScopedPointer>
#include "patient.h"
#include "bmi_calculator.h"
#include "bmr_calculator.h"
#include <QPair>

class PatientService
{
public:
    PatientService(QScopedPointer<BMI_Calculator> bmiCalc, QScopedPointer<BMR_Calculator> bmrCalc);

    // Methods
    void calculateMetrics(Patient& user) const;
    QString getBMIDescription() const;
    QString getBMRDescription() const;

private:
    // Strategy pattern for different calculation strategies
    QScopedPointer<BMI_Calculator> bmiCalculator;
    QScopedPointer<BMR_Calculator> bmrCalculator;

    // Helper methods
    QPair<float,float> idealWeight(Patient &user) const;
    float idealWaterIntake(Patient &user) const;
};

#endif // PATIENT_SERVICE_H

#include "patient_service.h"


PatientService::PatientService(QScopedPointer<BMI_Calculator> bmiCalc, QScopedPointer<BMR_Calculator> bmrCalc)
        : bmiCalculator(bmiCalc.take()),bmrCalculator(bmrCalc.take()) // Transfer ownership
    {
    }


void PatientService::calculateMetrics(Patient &user) const
{
    bmiCalculator->calculateBMI(user);
    bmrCalculator->calculateBMR(user);
    idealWeight(user);
    idealWaterIntake(user);
}

QPair<float,float> PatientService::idealWeight(Patient &user) const
{
    float minimum = (user.getHeight()/100.0) * (user.getHeight()/100.0) * 18.5;
    float maximum = (user.getHeight()/100.0) * (user.getHeight()/100.0) * 24.9;
    QPair<float,float> idealWeight(minimum,maximum);
    user.setIdealWeight(idealWeight);
    return idealWeight;
}

float PatientService::idealWaterIntake(Patient &user) const
{
    user.setIdealWaterIntake(user.getWeight() * 33);
    return user.getIdealWaterIntake();
}

QString PatientService::getBMIDescription() const
{
    return bmiCalculator->getDescription();
}

QString PatientService::getBMRDescription() const
{
    return bmrCalculator->getDescription();
}


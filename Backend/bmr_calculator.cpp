#include "bmr_calculator.h"

BMR_Calculator::BMR_Calculator()
{

}

BMR_Calculator::~BMR_Calculator()
{

}

float BMR_Calculator::calculateActivityFactor(const QString& activityLevel) const
{
    float factor = 0;
    if (activityLevel == "Sedentary") {
        factor = 1.2;
    } else if (activityLevel == "Lightly Active") {
        factor = 1.375;
    } else if (activityLevel == "Moderately Active") {
        factor = 1.55;
    } else if (activityLevel == "Very Active") {
        factor = 1.725;
    } else if (activityLevel == "Super Active") {
        factor = 1.9;
    }

    return factor;
}


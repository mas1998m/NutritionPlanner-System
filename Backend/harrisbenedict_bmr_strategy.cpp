#include "harrisbenedict_bmr_strategy.h"

HarrisBenedictBMRStrategy::HarrisBenedictBMRStrategy()
{

}

double HarrisBenedictBMRStrategy::calculateBMR(Patient & patient) const {
    float factor = calculateActivityFactor(patient.getActivityLevel());

    if(patient.getGender() == "Male"){
        patient.setBMR( (88.362 + (13.397 * patient.getWeight()) + (4.799 * patient.getHeight()) - (5.677 * patient.getAge())) * factor);
    }else{
        patient.setBMR( 447.593 + (9.247 * patient.getWeight()) + (3.098 * patient.getHeight()) - (4.330 * patient.getAge()) * factor);
    }

    return patient.getBMR();
}

QString HarrisBenedictBMRStrategy::getDescription() const {
    return "For men: BMR = 88.362 + (13.397 * weight in kg) + (4.799 * height in cm) - (5.677 * age in years)\n\
            For women: BMR = 447.593 + (9.247 * weight in kg) + (3.098 * height in cm) - (4.330 * age in years))";
}

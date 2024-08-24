#include "mifflinstjeor_bmr_strategy.h"

MifflinStJeorBMRStrategy::MifflinStJeorBMRStrategy()
{

}


double MifflinStJeorBMRStrategy::calculateBMR(Patient & patient) const {
    float factor = calculateActivityFactor(patient.getActivityLevel());

    if(patient.getGender() == "Male"){
        patient.setBMR(((10 * patient.getWeight()) + (6.25 * patient.getHeight()) - (5 * patient.getAge()) - 161) * factor);
    }else{
        patient.setBMR(((10 * patient.getWeight()) + (6.25 * patient.getHeight()) - (5 * patient.getAge()) + 5) * factor);
    }

    return patient.getBMR();
}

QString MifflinStJeorBMRStrategy::getDescription() const {
    return "For men: BMR = (10 * weight in kg) + (6.25 * height in cm) - (5 * age in years) - 161\n\
            For women: BMR = (10 * weight in kg) + (6.25 * height in cm) - (5 * age in years) + 5";
}

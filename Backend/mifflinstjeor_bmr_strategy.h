#ifndef MIFFLINSTJEOR_BMR_STRATEGY_H
#define MIFFLINSTJEOR_BMR_STRATEGY_H

#include "bmr_calculator.h"

class MifflinStJeorBMRStrategy : public BMR_Calculator
{
public:
    MifflinStJeorBMRStrategy();
    double calculateBMR(Patient & patient) const override;
    QString getDescription() const override;
};

#endif // MIFFLINSTJEOR_BMR_STRATEGY_H

#ifndef HARRISBENEDICT_BMR_STRATEGY_H
#define HARRISBENEDICT_BMR_STRATEGY_H

#include "bmr_calculator.h"

class HarrisBenedictBMRStrategy : public BMR_Calculator
{
public:
    HarrisBenedictBMRStrategy();
    double calculateBMR(Patient & patient) const override;
    QString getDescription() const override;
};

#endif // HARRISBENEDICT_BMR_STRATEGY_H

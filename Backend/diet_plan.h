#ifndef DIET_PLAN_H
#define DIET_PLAN_H

#include <QList>
#include "food_item.h"
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>



struct DailyNutritionInfo
{
    float totalCalories = 0.0f;
    float totalFats = 0.0f;
    float totalProtein = 0.0f;
    float totalCarbs = 0.0f;
};


class DietPlan
{
public:
    // Constructor
    DietPlan();

    // Methods
    // Accessors
    QList<QList<QList<FoodItem>>>& getPlan() ; // 7 days, 5 meals each
    QList<DailyNutritionInfo> analyzePlan() const;
    QJsonObject toJson() const;
    QJsonArray analyzePlanToJson() const;


private:
    QList<QList<QList<FoodItem>>> plan; // 7 days, each day has 5 meals, each meal has a list of food items
    DailyNutritionInfo calculateMealNutrition(const QList<FoodItem>& meal) const;

    // Helper function to generate a meal
};

#endif // DIET_PLAN_H

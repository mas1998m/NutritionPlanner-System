#include "diet_plan.h"


DietPlan::DietPlan()
{

}

QList<QList<QList<FoodItem>>> &DietPlan::getPlan()
{
    return plan;
}


QList<DailyNutritionInfo> DietPlan::analyzePlan() const
{
    QList<DailyNutritionInfo> nutritionSummary;

    // Iterate over each day
    for (const auto& dailyMeals : plan) {
        DailyNutritionInfo dailyInfo;

        // Iterate over each meal in the day
        for (const auto& meal : dailyMeals) {
            // Calculate nutrition for the meal and add it to the daily totals
            DailyNutritionInfo mealInfo = calculateMealNutrition(meal);
            dailyInfo.totalCalories += mealInfo.totalCalories;
            dailyInfo.totalFats += mealInfo.totalFats;
            dailyInfo.totalProtein += mealInfo.totalProtein;
            dailyInfo.totalCarbs += mealInfo.totalCarbs;
        }

        // Add the daily nutritional info to the summary
        nutritionSummary.append(dailyInfo);
    }

    return nutritionSummary;
}

QJsonObject DietPlan::toJson() const
{
    QJsonObject jsonObj;
    QJsonArray daysArray;

    // Iterate over days
    for (const auto& day : plan) {
        QJsonArray mealsArray;

        // Iterate over meals
        for (const auto& meal : day) {
            QJsonArray mealArray;

            // Add food items to the meal array
            for (const auto& foodItem : meal) {
                mealArray.append(foodItem.getName());
            }

            mealsArray.append(mealArray);
        }

        daysArray.append(mealsArray);
    }

    jsonObj["days"] = daysArray;
    return jsonObj;
}

// Helper function to calculate the nutritional information for a single meal
DailyNutritionInfo DietPlan::calculateMealNutrition(const QList<FoodItem>& meal) const
{
    DailyNutritionInfo mealInfo;

    // Sum up the nutritional values for each food item in the meal
    for (const auto& food : meal) {
        mealInfo.totalCalories += food.getCalories();
        mealInfo.totalFats += food.getFats();
        mealInfo.totalProtein += food.getProtein();
        mealInfo.totalCarbs += food.getCarbs();
    }

    return mealInfo;
}

QJsonArray DietPlan::analyzePlanToJson() const
{
    QList<DailyNutritionInfo> nutritionSummary = analyzePlan();
    QJsonArray jsonArray;

    // Iterate over the daily nutritional info
    for (const auto& info : nutritionSummary) {
        QJsonObject jsonObj;
        jsonObj["totalCalories"] = info.totalCalories;
        jsonObj["totalFats"] = info.totalFats;
        jsonObj["totalProtein"] = info.totalProtein;
        jsonObj["totalCarbs"] = info.totalCarbs;

        jsonArray.append(jsonObj);
    }

    return jsonArray;
}


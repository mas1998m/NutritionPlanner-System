#ifndef DIET_PLAN_SERVICE_H
#define DIET_PLAN_SERVICE_H

#include "diet_plan.h"
#include "food_item.h"

class DietPlanService
{
public:
    // Constructor
    DietPlanService();

    // Method to generate a diet plan
    DietPlan generateDietPlan() const;

private:
    // Food categories (each QList represents a category of food items)
    QList<FoodItem> Carbohydrates;
    QList<FoodItem> Proteins;
    QList<FoodItem> Fats;
    QList<FoodItem> Vegetables;
    QList<FoodItem> Fruits;
    QList<FoodItem> Sweets;

    // Helper function to initialize food categories
    void initializeCategories();

    // Helper function to get random food item from a category
    FoodItem getRandomFoodItem(const QList<FoodItem>& category) const;
};

#endif // DIET_PLAN_SERVICE_H

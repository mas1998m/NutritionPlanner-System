#include "diet_plan_service.h"

DietPlanService::DietPlanService()
{
    initializeCategories();
}

DietPlan DietPlanService::generateDietPlan() const
{
    DietPlan plan;
    // For each day (7 days)
    for (int day = 0; day < 7; ++day) {
        QList<QList<FoodItem>> dailyMeals;

        // Meal 1: Random food item from 1st category + 1 item from 2nd + 1 item from 3rd + 1 item from 4th
        QList<FoodItem> meal1;
        meal1.append(getRandomFoodItem(Carbohydrates));
        meal1.append(getRandomFoodItem(Proteins));
        meal1.append(getRandomFoodItem(Fats));
        meal1.append(getRandomFoodItem(Vegetables));
        dailyMeals.append(meal1);

        // Meal 2: Random food item from 5th category (Fruits)
        QList<FoodItem> meal2;
        meal2.append(getRandomFoodItem(Fruits));
        dailyMeals.append(meal2);

        // Meal 3: Same structure as Meal 1
        QList<FoodItem> meal3;
        meal3.append(getRandomFoodItem(Carbohydrates));
        meal3.append(getRandomFoodItem(Proteins));
        meal3.append(getRandomFoodItem(Fats));
        meal3.append(getRandomFoodItem(Vegetables));
        dailyMeals.append(meal3);

        // Meal 4: Random food item from 6th category (Sweets)
        QList<FoodItem> meal4;
        meal4.append(getRandomFoodItem(Sweets));
        dailyMeals.append(meal4);

        // Meal 5: Same structure as Meal 1
        QList<FoodItem> meal5;
        meal5.append(getRandomFoodItem(Carbohydrates));
        meal5.append(getRandomFoodItem(Proteins));
        meal5.append(getRandomFoodItem(Fats));
        meal5.append(getRandomFoodItem(Vegetables));
        dailyMeals.append(meal5);

        // Add the daily meals to the plan
        plan.getPlan().append(dailyMeals);
    }

    return plan;

}

void DietPlanService::initializeCategories()
{
    Carbohydrates.reserve(9);
    Proteins.reserve(9);
    Fats.reserve(9);
    Vegetables.reserve(9);
    Fruits.reserve(9);
    Sweets.reserve(9);

    Carbohydrates.append(FoodItem("Rice", 130, 2.7, 28.2, 0.3));
    Carbohydrates.append(FoodItem("Pasta", 131, 5.5, 25.1, 1.1));
    Carbohydrates.append(FoodItem("Bread", 266, 9.4, 49.4, 2.6));
    Proteins.append(FoodItem("Chicken", 165, 31.0, 0.0, 3.6));
    Proteins.append(FoodItem("Beef", 250, 26.0, 0.0, 17.0));
    Proteins.append(FoodItem("Fish", 206, 22.0, 0.0, 13.0));
    Fats.append(FoodItem("Butter", 717, 0.9, 0.0, 81.0));
    Fats.append(FoodItem("Olive Oil", 884, 0.0, 0.0, 100.0));
    Fats.append(FoodItem("Cheese", 402, 25.0, 3.0, 33.0));
    Vegetables.append(FoodItem("Broccoli", 55, 3.7, 10.0, 0.6));
    Vegetables.append(FoodItem("Spinach", 23, 2.9, 3.6, 0.4));
    Vegetables.append(FoodItem("Carrots", 41, 0.9, 10.0, 0.2));
    Fruits.append(FoodItem("Apple", 52, 0.3, 14.0, 0.2));
    Fruits.append(FoodItem("Banana", 89, 1.1, 23.0, 0.3));
    Fruits.append(FoodItem("Orange", 47, 1.0, 12.0, 0.1));
    Sweets.append(FoodItem("Chocolate", 546, 5.4, 61.5, 30.0));
    Sweets.append(FoodItem("Ice Cream", 207, 2.8, 24.0, 11.0));
    Sweets.append(FoodItem("Cake", 237, 2.1, 38.0, 8.0));

    Carbohydrates.append(FoodItem("Potato", 77, 2.0, 17.0, 0.1));
    Carbohydrates.append(FoodItem("Couscous", 112, 3.8, 23.2, 0.3));
    Carbohydrates.append(FoodItem("Quinoa", 120, 4.4, 21.3, 1.9));
    Proteins.append(FoodItem("Turkey", 135, 29.0, 0.0, 1.0));
    Proteins.append(FoodItem("Pork", 242, 26.0, 0.0, 16.0));
    Proteins.append(FoodItem("Lamb", 258, 25.0, 0.0, 17.0));
    Fats.append(FoodItem("Coconut Oil", 862, 0.0, 0.0, 100.0));
    Fats.append(FoodItem("Avocado", 160, 2.0, 9.0, 15.0));
    Fats.append(FoodItem("Nuts", 607, 15.0, 6.0, 56.0));
    Vegetables.append(FoodItem("Cauliflower", 25, 1.9, 5.0, 0.3));
    Vegetables.append(FoodItem("Zucchini", 17, 1.2, 3.1, 0.3));
    Vegetables.append(FoodItem("Bell Pepper", 31, 1.0, 6.0, 0.3));
    Fruits.append(FoodItem("Grapes", 69, 0.7, 18.0, 0.2));
    Fruits.append(FoodItem("Strawberries", 32, 0.7, 8.0, 0.3));
    Fruits.append(FoodItem("Watermelon", 30, 0.6, 8.0, 0.2));
    Sweets.append(FoodItem("Candy", 394, 0.0, 99.0, 0.0));
    Sweets.append(FoodItem("Donut", 452, 5.9, 49.0, 25.0));
    Sweets.append(FoodItem("Cookies", 502, 5.0, 68.0, 24.0));

    Carbohydrates.append(FoodItem("Rye Bread", 259, 8.0, 48.0, 2.0));
    Carbohydrates.append(FoodItem("Oats", 389, 17.0, 66.0, 7.0));
    Carbohydrates.append(FoodItem("Barley", 354, 12.0, 73.0, 2.0));
    Proteins.append(FoodItem("Salmon", 208, 20.0, 0.0, 13.0));
    Proteins.append(FoodItem("Shrimp", 99, 24.0, 0.0, 1.0));
    Proteins.append(FoodItem("Tofu", 144, 15.0, 3.0, 9.0));
    Fats.append(FoodItem("Sunflower Oil", 884, 0.0, 0.0, 100.0));
    Fats.append(FoodItem("Peanut Butter", 588, 25.0, 20.0, 50.0));
    Fats.append(FoodItem("Margarine", 717, 0.9, 0.0, 81.0));
    Vegetables.append(FoodItem("Kale", 35, 2.9, 6.7, 0.5));
    Vegetables.append(FoodItem("Cucumber", 15, 0.6, 3.6, 0.1));
    Vegetables.append(FoodItem("Mushrooms", 22, 3.1, 3.3, 0.3));
    Fruits.append(FoodItem("Pineapple", 50, 0.5, 13.0, 0.1));
    Fruits.append(FoodItem("Mango", 60, 0.8, 15.0, 0.4));
    Fruits.append(FoodItem("Kiwi", 61, 1.1, 15.0, 0.5));
    Sweets.append(FoodItem("Brownie", 466, 4.0, 66.0, 22.0));
    Sweets.append(FoodItem("Cupcake", 131, 1.5, 22.0, 4.0));
    Sweets.append(FoodItem("Pie", 237, 2.1, 38.0, 8.0));
}


FoodItem DietPlanService::getRandomFoodItem(const QList<FoodItem>& category) const
{
    int index = rand() % category.size();
    return category.at(index);
}

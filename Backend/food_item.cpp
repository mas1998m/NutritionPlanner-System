#include "food_item.h"


FoodItem::FoodItem(const QString &name, float calories, float protein, float carbs, float fats):
    name(name), calories(calories), protein(protein), carbs(carbs), fats(fats)
{

}

QString FoodItem::getName() const
{
    return name;
}

float FoodItem::getCalories() const
{
    return calories;
}

float FoodItem::getProtein() const
{
    return protein;
}

float FoodItem::getCarbs() const
{
    return carbs;
}

float FoodItem::getFats() const
{
    return fats;
}


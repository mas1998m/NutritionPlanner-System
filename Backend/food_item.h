#ifndef FOOD_ITEM_H
#define FOOD_ITEM_H

#include <QString>

class FoodItem
{
public:
    // Constructor
    FoodItem(const QString& name, float calories, float protein, float carbs, float fats);

    // Getters
    QString getName() const;
    float getCalories() const;
    float getProtein() const;
    float getCarbs() const;
    float getFats() const;

private:
    // Attributes
    QString name;
    float calories;
    float protein;
    float carbs;
    float fats;
};

#endif // FOOD_ITEM_H

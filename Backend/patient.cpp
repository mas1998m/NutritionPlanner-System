#include "patient.h"

Patient::Patient(QJsonObject jsonObj): BMI(0), BMR(0){
    name = jsonObj["name"].toString();
    age = jsonObj["age"].toString().toInt();
    gender = jsonObj["gender"].toString();
    height = jsonObj["height"].toString().toFloat();
    weight = jsonObj["weight"].toString().toFloat();
    waterIntake = jsonObj["waterIntake"].toString().toFloat();
    activityLevel = jsonObj["activityLevel"].toString();
    medicalConditions = jsonObj["medicalConditions"].toString().split(",");  // Assuming medical conditions are comma-separated
    targetWeight = jsonObj["targetWeight"].toString().toFloat();
}

const QString &Patient::getName() const
{
    return name;
}

void Patient::setName(const QString &name)
{
    this->name = name;
}

quint8 Patient::getAge() const
{
    return age;
}

void Patient::setAge(quint8 age)
{
    this->age = age;
}

const QString &Patient::getGender() const
{
    return gender;
}

void Patient::setGender(const QString &gender)
{
    this->gender = gender;
}

float Patient::getHeight() const
{
    return height;
}

void Patient::setHeight(float height)
{
    this->height = height;
}

float Patient::getWeight() const
{
    return weight;
}

void Patient::setWeight(float weight)
{
    this->weight = weight;
}

float Patient::getWaterIntake() const
{
    return waterIntake;
}

void Patient::setWaterIntake(float WaterIntake)
{
    this->waterIntake = WaterIntake;
}

const QString &Patient::getActivityLevel() const
{
    return activityLevel;
}

void Patient::setActivityLevel(const QString &activityLevel)
{
    this->activityLevel = activityLevel;
}

float Patient::getTargetWeight() const
{
    return targetWeight;
}

void Patient::setTargetWeight(float targetWeight)
{
    this->targetWeight = targetWeight;
}

const QList<QString> &Patient::getMedicalConditions() const
{
    return medicalConditions;
}

void Patient::setMedicalConditions(const QList<QString> &medicalConditions)
{
    this->medicalConditions = medicalConditions;
}

float Patient::getBMI() const
{
    return BMI;
}

void Patient::setBMI(float BMI)
{
    this->BMI = BMI;
}

float Patient::getBMR() const
{
    return BMR;
}

void Patient::setBMR(float BMR)
{
    this->BMR = BMR;
}

const QPair<float, float> &Patient::getIdealWeight() const
{
    return idealWeight;
}

void Patient::setIdealWeight(const QPair<float, float> &ideal)
{
    idealWeight = ideal;
}

float Patient::getIdealWaterIntake() const
{
    return idealWaterIntake;
}

void Patient::setIdealWaterIntake(float idealWaterIntake)
{
    this->idealWaterIntake = idealWaterIntake;
}





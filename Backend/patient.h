#ifndef PATIENT_H
#define PATIENT_H

#include <QString>
#include <QList>
#include <QJsonObject>
#include <QPair>

class Patient
{
public:
    // Constructors
    Patient()=delete;
    Patient(QJsonObject jsonObj);

    // Getters and Setters
    const QString & getName() const;
    void setName(const QString& name);

    quint8 getAge() const;
    void setAge(quint8 age);

    const QString& getGender() const;
    void setGender(const QString& gender);

    float getHeight() const;
    void setHeight(float height);

    float getWeight() const;
    void setWeight(float weight);

    float getWaterIntake() const;
    void setWaterIntake(float WaterIntake);

    const QString& getActivityLevel() const;
    void setActivityLevel(const QString& activityLevel);

    float getTargetWeight() const;
    void setTargetWeight(float targetWeight);

    const QList<QString>& getMedicalConditions() const;
    void setMedicalConditions(const QList<QString>& medicalConditions);

    float getBMI() const;
    void setBMI(float BMI);

    float getBMR() const;
    void setBMR(float BMR);

    const QPair<float, float>& getIdealWeight() const;
    void setIdealWeight(const QPair<float, float>& ideal);

    float getIdealWaterIntake() const;
    void setIdealWaterIntake(float idealWaterIntake);

    // Database operations
    void save() const; // Save user info to the database
    void update() const; // Update user info in the database

private:
    QString name;
    int age;
    QString gender;
    float height; // in cm
    float weight; // in kg
    float waterIntake; // in L
    QString activityLevel;
    float targetWeight; // in kg
    QList<QString> medicalConditions;
    float BMI;
    float BMR;
    QPair <float,float> idealWeight;
    float idealWaterIntake;
};

#endif // PATIENT_H

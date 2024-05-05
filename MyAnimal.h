#pragma once
#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Animal {
 private:
    int age;
    float mass;
    char* sex;
    char* color;

 public:
    Animal();
    Animal(int age, float mass, char* sex, char* color);
    Animal(const Animal& other);
    virtual ~Animal();
    Animal& operator=(const Animal& other);
    int GetAge() const;
    float GetMass() const;
    char* GetSex() const;
    char* GetColor() const;

    void SetAge(int n_age);
    void SetMass(float n_mass);
    void SetSex(const char* n_sex);
    void SetColor(const char* n_color);
    virtual void WhatDoesSay() const = 0;
};
class Dog : public Animal {
 public:
    enum class Breed {
        Pug,
        Bullterrier,
        Canes,
        Dalmatian,
        Doberman,
        Pekingese,
        Rottweiler,
        Poodle,
        Shepherd,
        Chihuahua
    };

 private:
    char* name;
    Breed race;

 public:
    Dog();
    Dog(int age, float mass, char* sex, char* color, char* name, Breed race);
    Dog(const Dog& other);
    ~Dog();
    Dog& operator=(const Dog& other);
    Dog& operator=(Dog&& other) noexcept;
    string GetRace() const;
    char* GetName() const;

    void SetRace(Breed n_race);
    void SetName(const char* n_name);
    void WhatDoesSay() const override;
};
class Fox : public Animal {
 public:
    enum class TypeFox {
        Bengal_fox,
        Arctic_fox,
        Tibetan_fox,
        Gray_fox,
        Red_fox
    };

 private:
    char* name;
    TypeFox type;
    int numberRabbitsEaten;

 public:
    Fox();
    Fox(int age, float mass, char* sex, char* color, char* name);
    Fox(const Fox& other);
    ~Fox();
    Fox& operator=(const Fox& other);
    Fox& operator=(Fox&& other) noexcept;
    char* GetName() const;
    string GetType() const;
    int GetNumberRabbitsEaten() const;

    void SetName(const char* n_name);
    void SetType(TypeFox n_race);
    void SetNumberRabbitsEaten(int numberRabbitsEaten);
    void Eat();
    void WhatDoesSay() const override;
};

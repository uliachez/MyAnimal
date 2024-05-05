#include "MyAnimal.h"

Animal::Animal() = default;

Animal::Animal(int age, float mass, char* sex, char* color) :
age(age), mass(mass), sex(sex), color(color) {}

Animal::Animal(const Animal& other) :
age(other.age), mass(other.mass), sex(other.sex), color(other.color) {}

Animal::~Animal() {
    delete[] sex;
    delete[] color;
}

Animal& Animal::operator=(const Animal& other) {
    if (this != &other) {
        age = other.age;
        mass = other.mass;
        sex = new char[strlen(other.sex) + 1];
        strcpy(sex, other.sex);
        color = new char[strlen(other.color) + 1];
        strcpy(color, other.color);
    }
    return *this;
}

int Animal::GetAge() const {
    return age;
}

float Animal::GetMass() const {
    return mass;
}

char* Animal::GetSex() const {
    return sex;
}

char* Animal::GetColor() const {
    return color;
}

void Animal::SetAge(int n_age) {
    age = n_age;
}

void Animal::SetMass(float n_mass) {
    mass = n_mass;
}

void Animal::SetSex(const char* n_sex) {
    sex = new char[strlen(n_sex) + 1];
    strcpy(sex, n_sex);
}

void Animal::SetColor(const char* n_color) {
    color = new char[strlen(n_color) + 1];
    strcpy(color, n_color);
}

Dog::Dog() = default;

Dog::Dog(int age, float mass, char* sex, char* color, char* name, Breed race)
: name(name), race(race) {}

Dog::Dog(const Dog& other) :
Animal(other), name(other.name), race(other.race) {}

Dog::~Dog() {
    delete[] name;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        race = other.race;
    }
    return *this;
}

Dog& Dog::operator=(Dog&& other) noexcept {
    if (this != &other) {
        Animal::operator=(move(other));
        name = other.name;
        other.name = nullptr;
        race = other.race;
    }
    return *this;
}

char* Dog::GetName() const {
    return name;
}

string Dog::GetRace() const {
    string breedName;
    switch (race) {
    case Breed::Pug:
        breedName = "Pug";
        break;
    case Breed::Bullterrier:
        breedName = "Bullterrier";
        break;
    case Breed::Canes:
        breedName = "Canes";
        break;
    case Breed::Dalmatian:
        breedName = "Dalmatian";
        break;
    case Breed::Doberman:
        breedName = "Doberman";
        break;
    case Breed::Pekingese:
        breedName = "Pekingese";
        break;
    case Breed::Rottweiler:
        breedName = "Rottweiler";
        break;
    case Breed::Poodle:
        breedName = "Poodle";
        break;
    case Breed::Shepherd:
        breedName = "Shepherd";
        break;
    case Breed::Chihuahua:
        breedName = "Chihuahua";
        break;
    default:
        breedName = "Unknown breed";
    }
    return breedName;
}

void Dog::SetRace(Breed n_race) {
    race = n_race;
}

void Dog::SetName(const char* n_name) {
    name = new char[strlen(n_name) + 1];
    strcpy(name, n_name);
}

void Dog::WhatDoesSay() const {
    cout << "Woof" << endl;
}

Fox::Fox() = default;

Fox::Fox(int age, float mass, char* sex, char* color, char* name)
: name(name) {}

Fox::Fox(const Fox& other) : Animal(other), name(other.name) {}

Fox::~Fox() {
    delete[] name;
}

Fox& Fox::operator=(const Fox& other) {
    if (this != &other) {
        Animal::operator=(other);
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
    }
    return *this;
}

Fox& Fox::operator=(Fox&& other) noexcept {
    if (this != &other) {
        Animal::operator=(move(other));
        name = other.name;
        other.name = nullptr;
    }
    return *this;
}

char* Fox::GetName() const {
    return name;
}

string Fox::GetType() const {
    string typeName;
    switch (type) {
    case TypeFox::Bengal_fox:
        typeName = "Bengal fox";
        break;
    case TypeFox::Arctic_fox:
        typeName = "Arctic fox";
        break;
    case TypeFox::Tibetan_fox:
        typeName = "Tibetan fox";
        break;
    case TypeFox::Gray_fox:
        typeName = "Gray fox";
        break;
    case TypeFox::Red_fox:
        typeName = "Red fox";
        break;
    default:
        typeName = "Unknown type";
    }
    return typeName;
}

int Fox::GetNumberRabbitsEaten() const {
    return numberRabbitsEaten;
}

void Fox::SetName(const char* n_name) {
    name = new char[strlen(n_name) + 1];
    strcpy(name, n_name);
}

void Fox::SetType(TypeFox n_type) {
    type = n_type;
}

void Fox::SetNumberRabbitsEaten(int numberRabbitsEaten) {
    this->numberRabbitsEaten = numberRabbitsEaten;
}

void Fox::Eat() {
    numberRabbitsEaten++;
}

void Fox::WhatDoesSay() const {
    switch (type) {
        case TypeFox::Arctic_fox:
            cout << "Ring-ding-ding-ding-dingeringeding!";
            break;
        case TypeFox::Bengal_fox:
            cout << "Wa-pa-pa-pa-pa-pa-pow!";
            break;
        case TypeFox::Gray_fox:
            cout << "Hatee-hatee-hatee-ho!";
            break;
        case TypeFox::Red_fox:
            cout << "Jacha-chacha-chacha-chow!";
            break;
        case TypeFox::Tibetan_fox:
            cout << "Fraka-kaka-kaka-kaka-kow!";
            break;
        default:
            cout << "A-oo-oo-oo-ooo!";
            break;
    }
}

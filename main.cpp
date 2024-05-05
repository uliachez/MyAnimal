#include "MyAnimal.h"
#include <ostream>

int main() {
    Animal *object;

    Dog object1;
    object1.SetAge(2);
    object1.SetMass(10.5);
    object1.SetSex("Female");
    object1.SetColor("Brown");
    object1.SetName("Lola");
    object1.SetRace(Dog::Breed::Shepherd);

    cout << "Dog:" << endl;

    cout << object1.GetAge() << endl;
    cout << object1.GetMass() << endl;
    cout << object1.GetSex() << endl;
    cout << object1.GetColor() << endl;
    cout << object1.GetName() << endl;
    object1.WhatDoesSay();
    cout << object1.GetRace() << endl;

    Fox object2;
    object2.SetAge(6);
    object2.SetMass(8.5);
    object2.SetSex("Male");
    object2.SetColor("Red");
    object2.SetName("Tom");
    object2.SetType(Fox::TypeFox::Red_fox);
    object2.SetNumberRabbitsEaten(3);

    cout << "Fox:" << endl;

    cout << object2.GetAge() << endl;
    cout << object2.GetMass() << endl;
    cout << object2.GetSex() << endl;
    cout << object2.GetColor() << endl;
    cout << object2.GetName() << endl;
    cout << object2.GetType() << endl;
    cout << object2.GetNumberRabbitsEaten() << endl;
    object2.Eat();
    cout << object2.GetNumberRabbitsEaten() << endl;
    object2.WhatDoesSay();
    return 0;
}

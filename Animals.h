#pragma once
#include <iostream>
#include <string>
#include "Animal.h"

class Elephant : public Animal {
public:
    Elephant(std::string name, int age)
        : Animal(name, "Elephant", age) {};

    void make_sound() override {
        std::cout << "Elephant " << getName() << " makes a trumpet sound" << std::endl;
    }
};

class Lion : public Animal {
public:
    Lion(std::string name, int age)
        : Animal(name, "Lion", age) {};

    void make_sound() override {
        std::cout << "Lion " << getName() << " roars" << std::endl;
    }
};

class Giraffe : public Animal {
public:
    Giraffe(std::string name, int age)
        : Animal(name, "Giraffe", age) {};

    void make_sound() override {
        std::cout << "Giraffe " << getName() << " makes a grunting sound" << std::endl;
    }
};

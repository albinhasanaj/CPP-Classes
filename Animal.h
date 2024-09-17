#pragma once
#include <iostream>
#include <string>
#include <cstdlib> // For system()

class Animal {
public:
    Animal(std::string name, std::string species, int age)
        : name(name), species(species), age(age) {}

    virtual void make_sound() {
        std::cout << "Animal " << name << " makes a sound" << std::endl;
    }

    std::string getName() const { return name; }
    std::string getSpecies() const { return species; }

    void showEnclosure() {
        std::string command;
#ifdef _WIN32
        // /images/elephant.png
        command = "start images\\" + species + ".png";
#elif __APPLE__
        command = "open " + species + ".png";
#else
        command = "xdg-open " + species + ".png";
#endif
        int result = system(command.c_str());
        if (result != 0) {
            std::cerr << "Failed to open image: " << species << ".png" << std::endl;
        }
    }


    ~Animal() {
        std::cout << "Animal " << name << " destroyed" << std::endl;
    }

private:
    std::string name;
    std::string species;
    int age;
};

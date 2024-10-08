#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Animal.h"

class Enclosure {
public:
    Enclosure(
        // --- Enclosure properties ---
        const std::string& name,
        int number,
        const std::string& climate,
        bool has_roof,
        float temperature,
        const std::vector<std::string>& animal_list,
        Enclosure* left_neighbour,
        Enclosure* right_neighbour,
        Animal* animal // Add Animal reference
    )
        // --- Initialize Enclosure properties ---
        : name(name), number(number), climate(climate), has_roof(has_roof), temperature(temperature),
        animal_list(animal_list), left_neighbour(left_neighbour), right_neighbour(right_neighbour), animal(animal) {};


    ~Enclosure() {
        std::cout << "Enclosure " << name << " destroyed" << std::endl;
    }

    void print_greeting() {
        std::cout << "\nWelcome to the " << name << " Enclosure" << std::endl;
        std::cout << "The climate is " << climate << std::endl;
        std::cout << "The temperature is " << temperature << " degrees" << std::endl;
        // Show the image of the animal
        if (animal) {
            animal->showEnclosure();
        }
    }

    void set_neighbours(Enclosure* enclosure, std::string direction) {
        if (direction == "left") {
            left_neighbour = enclosure;
        }
        else if (direction == "right") {
            right_neighbour = enclosure;
        }
    }

    Enclosure* get_neighbour(std::string direction) {
        if (direction == "left") {
            return left_neighbour;
        }
        else if (direction == "right") {
            return right_neighbour;
        }

        return nullptr;
    }

    std::string get_name() const { return name; }

private:
    std::string name;
    int number;
    std::string climate;
    bool has_roof;
    float temperature;
    std::vector<std::string> animal_list;
    Enclosure* left_neighbour;
    Enclosure* right_neighbour;
    Animal* animal; // Add reference to the associated Animal
};

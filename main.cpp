#include <iostream>
#include "Zoo.h"
#include "Enclosure.h"
#include <string>
#include <algorithm>

// populate zoo function
void populate_zoo(Zoo& zoo);
void zoo_loop(Zoo zoo);

int main() {
    std::cout << "Welcome to the Zoo\n" << std::endl;
    Zoo zoo("San Diego Zoo", "San Diego", 1916);

    populate_zoo(zoo);

    // Display greetings from all enclosures
    for (const auto& enclosure_pair : zoo.get_enclosures()) {
        Enclosure* enclosure = enclosure_pair.second;
        enclosure->print_greeting();
        std::cout << "-------------------\n" << std::endl;
    }

    zoo_loop(zoo);

    return 0;
}

void populate_zoo(Zoo& zoo) {
    Enclosure* LionEnclosure = new Enclosure("Lion", 1, "Tropical", true, 30.0, { "Lion", "Lioness" }, nullptr, nullptr);
    Enclosure* ElephantEnclosure = new Enclosure("Elephant", 2, "Tropical", true, 30.0, { "Elephant", "Elephant" }, nullptr, nullptr);
    Enclosure* GiraffeEnclosure = new Enclosure("Giraffe", 3, "Tropical", true, 30.0, { "Giraffe", "Giraffe" }, nullptr, nullptr);

    // Set neighbours for each enclosure
    LionEnclosure->set_neighbours(ElephantEnclosure, "right");
    ElephantEnclosure->set_neighbours(LionEnclosure, "left");
    ElephantEnclosure->set_neighbours(GiraffeEnclosure, "right");
    GiraffeEnclosure->set_neighbours(ElephantEnclosure, "left");

    zoo.add_enclosure(LionEnclosure);
    zoo.add_enclosure(ElephantEnclosure);
    zoo.add_enclosure(GiraffeEnclosure);

    // Set neighbours for each enclosure
}

void zoo_loop(Zoo zoo) {
    Enclosure* current_enclosure = nullptr;

    while (true) {
        std::cout << "command: ";
        std::string command;
        std::cin >> command;

        // Pointer to the current enclosure being visited

        //visit enclosure
        if (command == "visit") {
            std::cout << "Which enclosure would you like to visit? ";
            std::string enclosure_name;
            std::cin >> enclosure_name;

            // Convert enclosure name to lowercase for case-insensitive comparison
            std::transform(enclosure_name.begin(), enclosure_name.end(), enclosure_name.begin(), ::tolower);

            if (zoo.get_enclosure(enclosure_name) != nullptr) {
                current_enclosure = zoo.get_enclosure(enclosure_name);
                current_enclosure->print_greeting();
            }
            else {
                std::cout << "Enclosure not found" << std::endl;
            }
        }
        else if (command == "right") {
            if (current_enclosure == nullptr) {
                std::cout << "Please visit an enclosure first" << std::endl;
                continue;
            }

            if (current_enclosure->get_neighbour("right") != nullptr) {
                current_enclosure = current_enclosure->get_neighbour("right");
                current_enclosure->print_greeting();
            }
            else {
                std::cout << "No enclosure to the right" << std::endl;
            }
        }
        else if (command == "left") {
            if (current_enclosure == nullptr) {
                std::cout << "Please visit an enclosure first" << std::endl;
                continue;
            }

            if (current_enclosure->get_neighbour("left") != nullptr) {
                current_enclosure = current_enclosure->get_neighbour("left");
                current_enclosure->print_greeting();
            }
            else {
                std::cout << "No enclosure to the left" << std::endl;
            }
        }
        else if (command == "look") {
            if (current_enclosure == nullptr) {
                std::cout << "Please visit an enclosure first" << std::endl;
                continue;
            }
            current_enclosure->print_greeting();
        }
        else if (command == "exit") {
            break;
        }
        else {
            std::cout << "Invalid command" << std::endl;
        }
    };
}

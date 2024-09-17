#include <iostream>
#include "Zoo.h"
#include "Enclosure.h"
#include "Animals.h"
#include <string>
#include <algorithm>

// populate zoo function
void populate_zoo(Zoo& zoo);
void zoo_loop(Zoo zoo);

int main() {
    std::cout << "Welcome to the Zoo\n" << std::endl;
    Zoo zoo("San Diego Zoo", "San Diego", 1916);

    populate_zoo(zoo);

    zoo_loop(zoo);

    return 0;
}

void populate_zoo(Zoo& zoo) {
    Animal* elephant = new Elephant("Dumbo", 10);
    Animal* lion = new Lion("Simba", 5);
    Animal* giraffe = new Giraffe("Gerald", 7);

    Enclosure* elephant_enclosure = new Enclosure(elephant->getSpecies(), 1, "Tropical", true, 25.0, { elephant->getName() }, nullptr, nullptr, elephant);

    Enclosure* lion_enclosure = new Enclosure(lion->getSpecies(), 2, "Savannah", false, 30.0, { lion->getName() }, nullptr, nullptr, lion);

    Enclosure* giraffe_enclosure = new Enclosure(giraffe->getSpecies(), 3, "Savannah", true, 30.0, { giraffe->getName() }, nullptr, nullptr, giraffe);

    elephant_enclosure->set_neighbours(lion_enclosure, "right");
    lion_enclosure->set_neighbours(giraffe_enclosure, "right");
    lion_enclosure->set_neighbours(elephant_enclosure, "left");
    giraffe_enclosure->set_neighbours(lion_enclosure, "left");

    zoo.add_enclosure(elephant_enclosure);
    zoo.add_enclosure(lion_enclosure);
    zoo.add_enclosure(giraffe_enclosure);
}


void zoo_loop(Zoo zoo) {
    Enclosure* current_enclosure = nullptr;

    while (true) {
        std::cout << "command: ";
        std::string command;
        std::cin >> command;

        if (command == "visit") {
            std::cout << "Which enclosure would you like to visit? ";
            std::string enclosure_name;
            std::cin >> enclosure_name;

            std::transform(enclosure_name.begin(), enclosure_name.end(), enclosure_name.begin(), ::tolower);

            current_enclosure = zoo.get_enclosure_by_name(enclosure_name);

            if (current_enclosure != nullptr) {
                current_enclosure->print_greeting();
            }
            else {
                std::cout << "Enclosure not found" << std::endl;
            }
        }
        else if (command == "list") {
            zoo.list_enclosures();
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
    }
}
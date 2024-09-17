#pragma once
#include <map>
#include <string>
#include "Enclosure.h"
#include <algorithm>

class Zoo {
public:
    Zoo(
        // --- Zoo properties ---
        const std::string& name,
        const std::string& location,
        int year_built)
        // --- Initialize Zoo properties ---
        : name(name), location(location), year_built(year_built) {}

    std::map<std::string, std::string> get_info() {
        std::map<std::string, std::string> info;
        info["name"] = name;
        info["location"] = location;
        info["year_built"] = std::to_string(year_built);
        return info;
    }

    void list_enclosures() {
        std::cout << "Enclosures in the Zoo:" << std::endl;
        for (const auto& pair : enclosure_list) {
            std::cout << pair.first << std::endl;
        }
    }

    void add_enclosure(Enclosure* enclosure) {
        std::string lower_case_name = enclosure->get_name();
        std::transform(lower_case_name.begin(), lower_case_name.end(), lower_case_name.begin(), ::tolower);
        enclosure_list[lower_case_name] = enclosure;
    }

    Enclosure* get_enclosure_by_name(const std::string& name) {
        std::string lower_case_name = name;
        std::transform(lower_case_name.begin(), lower_case_name.end(), lower_case_name.begin(), ::tolower);
        auto it = enclosure_list.find(lower_case_name);
        if (it != enclosure_list.end()) {
            return it->second;
        }
        return nullptr;
    }

    std::map<std::string, Enclosure*> get_enclosures() {
        return enclosure_list;
    }


    ~Zoo() {
        // Delete all Enclosures from heap memory
        for (auto& pair : enclosure_list) {
            delete pair.second;
        }
        enclosure_list.clear();
    }

private:
    std::string name;
    std::string location;
    int year_built;
    // Store Enclosures in a map with the enclosure name as the key
    std::map<std::string, Enclosure*> enclosure_list;
};

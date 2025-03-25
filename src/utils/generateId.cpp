#include "generateId.hpp"
#include "generateRandomNumber.hpp"

#include <string>

std::string generateId() {
    std::string id = "";
    for (int i=0; i < 5; i++) {
        int random_number = generateRandomNumber() * 10.0;
        id += std::to_string(random_number);
    }
    return id;
}
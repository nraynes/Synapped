#include "generateRandomNumber.hpp"

#include <random>

double generateRandomNumber() {
    static std::random_device rd;
    static std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(rng);
}
#include "readCSV.h"

#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

std::vector<std::array<std::vector<double>, 2>> readCSV(const std::string& filename, int dataSplitPoint) {
    std::vector<std::array<std::vector<double>, 2>> data;
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Error opening file.\n";
        return data;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::vector<double> row;
        std::stringstream ss(line);
        std::string cell;

        while (std::getline(ss, cell, ',')) {
            try {
                row.push_back(std::stod(cell));
            } catch (const std::invalid_argument& e) {
                std::cerr << "Invalid number: " << cell << "\n";
                row.push_back(0.0); // or handle differently
            }
        }
        std::vector<double> inputData(row.begin(), row.begin() + dataSplitPoint);
        std::vector<double> outputData(row.begin() + dataSplitPoint, row.end());
        std::array<std::vector<double>, 2> separatedData = {inputData, outputData};
        data.push_back(separatedData);
    }

    file.close();
    return data;
}
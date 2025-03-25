#pragma once

#include <vector>

std::vector<std::array<std::vector<double>, 2>> readCSV(const std::string& filename, int dataSplitPoint);

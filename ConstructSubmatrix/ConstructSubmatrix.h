#pragma once
#include <vector>

std::vector<std::vector<int>> constructSubmatrix(std::vector<std::vector<int>> matrix, std::vector<int> rowsToDelete, std::vector<int> columnsToDelete);
std::vector<std::vector<int>> DeleteRows(std::vector<std::vector<int>> matrix, std::vector<int> rowsToDelete);
std::vector<std::vector<int>> DeleteColumns(std::vector<std::vector<int>> matrix, std::vector<int> columnsToDelete);
bool Contain(std::vector<int> vector, int value);


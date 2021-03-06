// ConstructSubmatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConstructSubmatrix.h"

int main()
{
	std::vector<std::vector<int>> matrix = 
	{
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
	};

	std::vector<int> rowsToDelete = { 1 };
	std::vector<int> columnsToDelete = { 1,2 };

	std::vector<std::vector<int>> matrix1 = constructSubmatrix(matrix, rowsToDelete, columnsToDelete);
    return 0;
}

std::vector<std::vector<int>> constructSubmatrix(std::vector<std::vector<int>> matrix, std::vector<int> rowsToDelete, std::vector<int> columnsToDelete) {
	std::vector<std::vector<int>> matrix1 = DeleteRows(matrix, rowsToDelete);
	std::vector<std::vector<int>> matrix2 = DeleteColumns(matrix1, columnsToDelete);

	return matrix2;
}

std::vector<std::vector<int>> DeleteRows(std::vector<std::vector<int>> matrix, std::vector<int> rowsToDelete)
{
	std::vector<std::vector<int>> result;
	for (unsigned int i = 0; i < matrix.size(); ++i)
	{
		if (!Contain(rowsToDelete, i))
		{
			result.push_back(matrix[i]);
		}
	}
	return result;
}

std::vector<std::vector<int>> DeleteColumns(std::vector<std::vector<int>> matrix, std::vector<int> columnsToDelete)
{
	std::vector<std::vector<int>> result;
	for (unsigned int j = 0; j < matrix.size(); ++j)
	{
		std::vector<int> row = matrix[j];
		std::vector<int> rowDeleted;
		for (unsigned int i = 0; i < row.size(); ++i)
		{
			if (!Contain(columnsToDelete, i))
			{
				rowDeleted.push_back(row[i]);
			}
		}
		result.push_back(rowDeleted);
	}

	return result;
}

bool Contain(std::vector<int> vector, int value)
{
	for (unsigned int i = 0; i < vector.size(); ++i)
	{
		if (vector[i] == value)
		{
			return true;
		}
	}
	return false;
}

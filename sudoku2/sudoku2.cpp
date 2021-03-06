// sudoku2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <string>

bool sudoku2(std::vector<std::vector<char>> grid);
std::vector<int> RowNum(std::vector<std::vector<char>> grid, int rowInd);
std::vector<int> ColNum(std::vector<std::vector<char>> grid, int colInd);
std::vector<int> SquareNum(std::vector<std::vector<char>> grid, int rowStart, int colStart);
bool IsValidate(std::vector<int> range);
int ToNum(char c);

int main()
{
	std::vector<std::vector<char>> grid = {
		{ '.', '.', '.', '.', '2', '.', '.', '9', '.' },
		{ '.', '.', '.', '.', '6', '.', '.', '.', '.' },
		{ '7', '1', '.', '.', '7', '5', '.', '.', '.' },
		{ '.', '7', '.', '.', '.', '.', '.', '.', '.' },
		{ '.', '.', '.', '.', '8', '3', '.', '.', '.' },
		{ '.', '.', '8', '.', '.', '7', '.', '6', '.' },
		{ '.', '.', '.', '.', '.', '2', '.', '.', '.' },
		{ '.', '1', '.', '2', '.', '.', '.', '.', '.' },
		{ '.', '2', '.', '.', '3', '.', '.', '.', '.' }
	};

	bool ret = sudoku2(grid);
	return 0;
}

bool sudoku2(std::vector<std::vector<char>> grid) {
	size_t size = grid.size();

	// Row, column validate
	for (size_t i = 0; i < size; ++i)
	{
		std::vector<int> row = RowNum(grid, i);
		std::vector<int> col = ColNum(grid, i);
		bool validate = IsValidate(row) && IsValidate(col);
		if (!validate)
		{
			return false;
		}
	}

	// Square validate
	for (size_t i = 0; i < size; i += 3)
	{
		for (size_t j = 0; j < size; j += 3)
		{
			std::vector<int> square = SquareNum(grid, i, j);
			if (!IsValidate(square))
			{
				return false;
			}
		}
	}

	return true;
}

std::vector<int> RowNum(std::vector<std::vector<char>> grid, int rowInd)
{
	std::vector<char> row = grid[rowInd];

	std::vector<int> rowNum;
	size_t size = row.size();
	for (size_t i = 0; i < size; ++i)
	{
		rowNum.push_back(ToNum(row[i]));
	}
	return rowNum;
}

std::vector<int> ColNum(std::vector<std::vector<char>> grid, int colInd)
{
	std::vector<int> colNum;
	size_t size = grid.size();

	for (size_t i = 0; i < size; ++i)
	{
		colNum.push_back(ToNum(grid[i][colInd]));
	}
	return colNum;
}

std::vector<int> SquareNum(std::vector<std::vector<char>> grid, int rowStart, int colStart)
{
	std::vector<int> squareNum;
	for (size_t i = rowStart; i < rowStart + 3; ++i)
	{
		for (size_t j = colStart; j < colStart + 3; ++j)
		{
			squareNum.push_back(ToNum(grid[i][j]));
		}
	}
	return squareNum;
}

bool IsValidate(std::vector<int> range)
{
	bool used[10] = { false };
	size_t size = range.size();
	for (size_t i = 0; i < size; ++i)
	{
		if (range[i] > 0 && used[range[i]])
		{
			return false;
		}
		used[range[i]] = true;
	}
	return true;
}

int ToNum(char c)
{
	if (!isdigit(c) || c == '0')
	{
		return 0;
	}

	return c - 48;
}
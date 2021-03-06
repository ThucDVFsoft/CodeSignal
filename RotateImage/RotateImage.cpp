// RotateImage.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>

std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a);

int main()
{
	std::vector<std::vector<int>> a = { {1, 2, 3},
	{4, 5, 6 },
		{7, 8, 9} };
	std::vector<std::vector<int>> ret = rotateImage(a);
    return 0;
}
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
	std::vector<std::vector<int>> ret;

	for (int i = 0; i< a.size(); i++)
	{
		std::vector<int> rowRotated;
		for (int j = a.size() - 1; j >= 0; j--)
		{
			std::vector<int> row = a[j];
			rowRotated.push_back(row[i]);
		}
		ret.push_back(rowRotated);
	}

	return ret;
}


// ConstructArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ConstructArray.h"

int main()
{
	int size = 8;
	std::vector<int> ret = constructArray(size);
    return 0;
}

std::vector<int> constructArray(int size) {

	std::vector<int> results;
	for (int i = 0; i < size/2 ; i++)
	{
		results.push_back(i + 1);
		
		results.push_back(size - i);
	}
	if (size % 2 != 0)
	{
		results.push_back(size / 2 + 1);
	}
	return results;
}


// Zigzag.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>

int zigzag(std::vector<int> a);
bool IsZigzagNumber(int backwardNeighbour, int num, int towardNeighbour);
std::vector<int> ZigzagsLenght(std::vector<int> vector);


int main()
{
	std::vector<int> v = {
		2, 1, 4, 4, 1, 4, 4, 1, 2, 0, 1, 0, 0, 3, 1, 3, 4, 1, 3, 4
	};

	int len = zigzag(v);

	std::cout << len;
    return 0;
}

int zigzag(std::vector<int> a) {
	std::vector<int> lens = ZigzagsLenght(a);

	int maxlen = 0;
	for (int i = 0; i < lens.size(); i++)
	{
		if (lens[i] > maxlen)
		{
			maxlen = lens[i];
		}
	}

	return maxlen;
}

bool IsZigzagNumber(int backwardNeighbour, int num, int towardNeighbour)
{
	if ((num < backwardNeighbour && num < towardNeighbour)
		|| (num > backwardNeighbour && num > towardNeighbour))
	{
		return true;
	}

	return false;
}

std::vector<int> ZigzagsLenght(std::vector<int> vector)
{
	std::vector<int> lens;
	bool sequenceFlag = true;
	int len = 1;

	int size = vector.size();
	for (int i = 1; i < size -1; i++)
	{
		if (IsZigzagNumber(vector[i - 1], vector[i], vector[i + 1]))
		{
			len++;
		}
		else
		{
			lens.push_back(++len);
			len = 1;
		}
	}

	// last element
	if (vector[size - 1] != vector[size - 2])
	{
		len++;
	}
	lens.push_back(len);

	return lens;
}
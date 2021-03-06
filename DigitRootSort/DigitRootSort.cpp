// DigitRootSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
#include <algorithm> 

std::vector<int> digitRootSort(std::vector<int> a);
void SortByValue(std::vector<int> &nums);
std::map<int, std::vector<int>> SortBySum(std::vector<int> a);
void AddRange(std::vector<int> &src, std::vector<int> &dest);
int Sum(int num);

int main()
{
	std::vector<int> input = { 12, 25, 16, 7, 3, 14, 51, 6, 24, 33 };
	std::vector<int> output = digitRootSort(input);

    return 0;
}

std::vector<int> digitRootSort(std::vector<int> a) {
	std::vector<int> results;
	std::map<int, std::vector<int>> map = SortBySum(a);

	for (std::map<int, std::vector<int>>::iterator mapIter = map.begin(); mapIter != map.end(); ++mapIter)
	{
		std::vector<int> nums = mapIter->second;
		SortByValue(nums);
		AddRange(nums, results);
	}

	return results;
}

std::map<int, std::vector<int>> SortBySum(std::vector<int> a)
{
	//vector<sum, vector<num>>
	std::map<int, std::vector<int>> map;
	int size = a.size();
	for (int i = 0; i < size; ++i)
	{
		int sum = Sum(a[i]);

		std::map<int, std::vector<int>>::iterator mapIter = map.find(sum);
		if (mapIter != map.end())
		{
			(mapIter->second).push_back(a[i]);
		}
		else
		{
			std::vector<int> numVector = { a[i] };
			map[sum] = numVector;
		}
	}

	return map;
}

void AddRange(std::vector<int> &src, std::vector<int> &dest)
{
	for (int i = 0; i < src.size(); ++i)
	{
		dest.push_back(src[i]);
	}
}

int Sum(int num)
{
	int sum = 0;
	for (; num; num /= 10)
	{
		sum += num % 10;
	}
	return sum;
}

void SortByValue(std::vector<int> &nums)
{
	std::sort(nums.begin(), nums.end());
}
// LuckyNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<list>
#include<iostream>

bool isLucky(int n);
std::vector<int> Storage(int number, int &count);
int Sum(std::vector<int> vector, int begin, int end);

int main()
{
	int num = 0;
	std::cin >> num;
	bool lucky = isLucky(num);

	std::cout << lucky;
    return 0;
}

bool isLucky(int n) {
	bool flag = false;

	int count = 0;
	std::vector<int> storage = Storage(n, count);
	if (count % 2 == 0)
	{
		int middle = count / 2;

		int firstHaft = Sum(storage, 0, middle);
		int lastHaft = Sum(storage, middle, count);

		if (firstHaft == lastHaft)
		{
			flag = true;
		}
	}

	return flag;
}

std::vector<int> Storage(int number, int &count)
{
	count = 0;
	std::vector<int> ret;
	for (; number; number /= 10)
	{
		ret.push_back(number % 10);
		count++;
	}

	return ret;
}

int Sum(std::vector<int> vector, int begin, int end)
{
	int sum = 0;
	for (int i = begin; i < end; ++i)
	{
		sum += vector.at(i);
	}

	return sum;
}


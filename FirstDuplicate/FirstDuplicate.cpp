// FirstDuplicate.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <map>
int firstDuplicate(std::vector<int> a);

int main()
{

    return 0;
}

int firstDuplicate(std::vector<int> a) {
	int size = a.size();
	std::map<int, int> map;
	for (int i = 0; i < size; i++)
	{
		if (map.find(a[i]) != map.end())
		{
			return a[i];
		}
		else
		{
			map[a[i]] = a[i];
		}
	}

	return -1;
}
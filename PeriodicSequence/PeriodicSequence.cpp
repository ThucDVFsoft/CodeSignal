// PeriodicSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PeriodicSequence.h"

int main()
{
	int ret = periodicSequence(11, 2, 6, 12);
    return 0;
}

int periodicSequence(int s0, int a, int b, int m) {
	std::map<int, int> map;
	int prevValue = s0;
	int currentValue = s0;
	int occuredAt = -1;

	for (int i = 0; ; ++i)
	{
		currentValue = (a * prevValue + b) % m;

		if (TryGetValue(map, currentValue, occuredAt))
		{
			return (i - occuredAt);
		}
		else
		{
			map[currentValue] = i;
			prevValue = currentValue;
		}
	}
}


bool TryGetValue(std::map<int, int> map, int key, int &out)
{
	std::map<int, int>::iterator mapIter = map.find(key);
	if (mapIter != map.end())
	{
		out = mapIter->second;
		return true;
	}

	return false;
}
// checkPalindrome.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
bool checkPalindrome(std::string inputString);

int main()
{
	checkPalindrome("hlbeeykoqqqqokyeeblh");
    return 0;
}

bool checkPalindrome(std::string inputString) {
	int len = inputString.length();
	if (len == 1) return true;

	int middle = len / 2;
	if (len % 2 == 0)
	{
		inputString = inputString.insert(middle, "_");
		len = inputString.length();
	}
	for (int i = 0; i < middle; i++)
	{
		if (inputString[i] != inputString[len - i - 1])
		{
			return false;
		}
	}

	return true;
}

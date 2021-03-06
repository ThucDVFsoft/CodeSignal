// NewNumeralSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<iostream>
#include"NewNumeralSystemDefinition.h"



std::vector<std::string> newNumeralSystem(char numberChar);
int CharToNumber(char numberChar);
char NumberToChar(int number);
std::vector<std::string>  AddUpNum(int num);
std::string GetResult(char letter1, char letter2);

int main()
{
	char input;
	std::cin >> input;
	std::vector<std::string> results = newNumeralSystem(input);
	return 0;
}

std::vector<std::string> newNumeralSystem(char number) {
	std::vector<std::string> ret;

	int num = CharToNumber(number);
	if (num >= 0 && num < 26)
	{
		ret = AddUpNum(num);
	}
	return ret;
}

int CharToNumber(char numberChar)
{
	int number = -1;

	std::map<char, int>::iterator mapIter = charIntMap.find(numberChar);
	if (mapIter != charIntMap.end())
	{
		number = mapIter->second;
	}

	return number;
}

char NumberToChar(int number)
{
	char chr = '-';

	std::map<int, char>::iterator mapIter = intCharMap.find(number);
	if (mapIter != intCharMap.end())
	{
		chr = mapIter->second;
	}

	return chr;
}

std::vector<std::string>  AddUpNum(int num)
{
	std::vector<std::string> ret;

	int middle = num / 2;
	char letter1 = '-';
	char letter2 = '-';

	for (int i = 0; i <= middle; ++i)
	{
		letter1 = NumberToChar(i);
		letter2 = NumberToChar(num - i);

		std::string total = GetResult(letter1, letter2);
		ret.push_back(total);
	}

	return ret;
}

std::string GetResult(char letter1, char letter2)
{
	std::string result;
	std::string water = " + ";

	result += letter1;
	result += water;
	result += letter2;

	return result;
}


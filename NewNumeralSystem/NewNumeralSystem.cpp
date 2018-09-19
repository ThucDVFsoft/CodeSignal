// NewNumeralSystem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<map>
#include<iostream>
#include"NewNumeralSystemDefinition.h"

using namespace std;

std::vector<std::string> newNumeralSystem(char numberChar);
int CharToNumber(char numberChar);
char NumberToChar(int number);
vector<string>  AddUpNum(int num);
string GetResult(char letter1, char letter2);

int main()
{
	char input;
	cin >> input;
	std::vector<std::string> results = newNumeralSystem(input);
	return 0;
}

std::vector<std::string> newNumeralSystem(char numberChar) 
{
	std::vector<std::string> ret;

	int number = CharToNumber(numberChar);
	if (number >= 0 && number < 26)
	{
		ret = AddUpNum(number);
	}
	return ret;
}

int CharToNumber(char numberChar)
{
	int number = -1;

	map<char, int>::iterator mapIter = charIntMap.find(numberChar);
	if (mapIter != charIntMap.end())
	{
		number = mapIter->second;
	}

	return number;
}

char NumberToChar(int number)
{
	char chr = '-';

	map<int, char>::iterator mapIter = intCharMap.find(number);
	if (mapIter != intCharMap.end())
	{
		chr = mapIter->second;
	}

	return chr;
}

vector<string>  AddUpNum(int num)
{
	vector<string> ret;

	int middle = num / 2;
	char letter1 = '-';
	char letter2 = '-';

	for (int i = 0; i <= middle; ++i)
	{
		letter1 = NumberToChar(i);
		letter2 = NumberToChar(num - i);

		string total = GetResult(letter1, letter2);
		ret.push_back(total);
	}

	return ret;
}

string GetResult(char letter1, char letter2)
{
	string result;
	string water = " + ";

	result += letter1;
	result += water;
	result += letter2;

	return result;
}


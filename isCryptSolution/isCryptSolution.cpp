// isCryptSolution.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution);
bool Crypt(std::string str, std::vector<std::vector<char>> solution, int &num);

int main()
{
	std::vector<std::string> crypt = { "A","A","A" };
	std::vector<std::vector<char>> solution = { { 'A','0' } };

	bool ret = isCryptSolution(crypt, solution);

    return 0;
}

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
	size_t size = crypt.size();
	if (size == 3)
	{
		std::string a = crypt[0];
		std::string b = crypt[1];
		std::string c = crypt[2];

		int numA = 0;
		int numB = 0;
		int numC = 0;

		if (Crypt(a, solution, numA)
			&& Crypt(b, solution, numB)
			&& Crypt(c, solution, numC))
		{
			if (numA + numB == numC)
			{
				return true;
			}
			return false;
		}
		return false;
	}
	return false;
}

bool Crypt(std::string str, std::vector<std::vector<char>> solution, int &num)
{
	num = 0;
	size_t strLen = str.length();
	size_t solSize = solution.size();

	for (size_t i = 0; i < strLen; ++i)
	{
		char c = str[i];
		for (size_t j = 0; j < solSize; ++j)
		{
			if (c == solution[j][0])
			{
				if (i == 0 && strLen > 1 && solution[j][1] == '0')
				{
					return false;
				}
				num = num * 10 + solution[j][1] - 48;
			}
		}
	}
	return true;
}
// DecodeString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DecodeString.h"

int main()
{
	std::string s = "2[b3[a]]";
	std::string ret = decodeString(s);
    return 0;
}

std::string decodeString(std::string s)
{
	std::stack<int> integerstack;
	std::stack<char> stringstack;
	std::string temp = "", result = "";

	for (unsigned int i = 0; i < s.length(); i++)
	{
		int count = 0;

		if (isdigit(s[i]))
		{
			count = GetNumber(s, i);
			integerstack.push(count);
		}

		else if (s[i] == ']')
		{
			temp = "";
			count = 0;

			if (!integerstack.empty())
			{
				count = integerstack.top();
				integerstack.pop();
			}
			temp = GetString(stringstack);

			result = Decode(count, temp);

			for (unsigned int j = 0; j < result.length(); j++)
			{
				stringstack.push(result[j]);
			}

			result = "";
		}
		else
		{
			stringstack.push(s[i]);
		}
	}

	// Pop all the elmenet, make a string and return.
	while (!stringstack.empty())
	{
		result = stringstack.top() + result;
		stringstack.pop();
	}

	return result;
}

int GetNumber(std::string str, unsigned int &i)
{
	if (!isdigit(str[i])) return 0;

	for (unsigned int j = i; j < str.length(); ++j)
	{
		if (!isdigit(str[j]))
		{
			std::string numString = str.substr(i, j - i);
			i = j - 1;
			return std::stoi(numString);
		}
	}
	return 0;
}

std::string GetString(std::stack<char> &stringstack)
{
	std::string strRet = "";
	std::string temp = "";
	while (!stringstack.empty() && stringstack.top() != '[')
	{
		temp = stringstack.top();
		strRet = temp + strRet;
		stringstack.pop();
	}

	if (!stringstack.empty() && stringstack.top() == '[')
	{
		stringstack.pop();
	}

	return strRet;
}

std::string Decode(int num, std::string str)
{
	std::string ret = "";
	for (int i = 0; i < num; ++i)
	{
		ret += str;
	}
	return ret;
}

#pragma once
#include <string>
#include <cctype>
#include <stack>

std::string decodeString(std::string s);
int GetNumber(std::string str, unsigned int &i)									;
std::string GetString(std::stack<char> &stringstack);
std::string Decode(int num, std::string str)							;


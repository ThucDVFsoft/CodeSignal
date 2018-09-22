#pragma once
#include <vector>
#include <string>



std::vector<int> bankRequests(std::vector<int> accounts, std::vector<std::string> requests);
std::vector<std::vector<int>> ConvertToInt(std::vector<std::string> requests);
void Calculate(std::vector<int> &accounts, std::vector<std::vector<int>> requests);
std::vector<std::string> Split(std::string s, std::string delimiter);
std::vector<std::vector<int>> ConvertToInt(std::vector<std::vector<std::string>> requests);
std::vector<int> WithdrawConvertToInt(std::vector<std::string> withdraw);
std::vector<int> TransferConvertToInt(std::vector<std::string> transfer);
std::vector<int> DepositConvertToInt(std::vector<std::string> deposit);
std::vector<int> DepositConvertToInt(std::vector<std::string> deposit);
bool WithdrawCalculate(std::vector<int> &accounts, std::vector<int> withdraw);
bool TransferCalculate(std::vector<int> &accounts, std::vector<int> transfer);
bool DepositCalculate(std::vector<int> &accounts, std::vector<int> deposit);

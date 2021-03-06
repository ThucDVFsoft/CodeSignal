// bankRequests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "bankRequests.h"



int main()
{
	std::vector<int> accounts = { 10, 100, 20, 50, 30 };
	std::vector<std::string> requests = { "withdraw 2 10",
		"transfer 5 1 20",
		"deposit 5 20",
		"transfer 3 4 15" };
	std::vector<int> ret = bankRequests(accounts, requests);
	return 0;
}

#define D_DELIMITER " "
enum ERequestType
{
	Withdraw = 0,
	Transfer,
	Deposit
};
std::vector<int> bankRequests(std::vector<int> accounts, std::vector<std::string> requests) {
	std::vector<std::vector<int>> requestsInt = ConvertToInt(requests);
	Calculate(accounts, requestsInt);
	return accounts;
}

std::vector<std::vector<int>> ConvertToInt(std::vector<std::string> requests)
{
	std::vector<std::vector<int>> ret;
	std::vector<std::string> result;
	std::vector<std::vector<std::string>> requestsSplited;

	size_t size = requests.size();
	for (unsigned int i = 0; i < size; ++i)
	{
		std::string request = requests[i];
		result = Split(request, D_DELIMITER);
		requestsSplited.push_back(result);
	}

	ret = ConvertToInt(requestsSplited);
	return ret;
}

void Calculate(std::vector<int> &accounts, std::vector<std::vector<int>> requests)
{
	size_t size = requests.size();
	std::vector<int> request;
	for (unsigned int i = 0; i < size; ++i)
	{
		request = requests[i];
		switch (request[0])
		{
		case Withdraw:
			if (!WithdrawCalculate(accounts, request))
			{
				accounts.clear();
				accounts.push_back(0 - i -1);
				return;
			}
			break;
		case Transfer:
			if (!TransferCalculate(accounts, request))
			{
				accounts.clear();
				accounts.push_back(0 - i - 1);
				return;
			}
			break;
		case Deposit:
			if (!DepositCalculate(accounts, request))
			{
				accounts.clear();
				accounts.push_back(0 - i - 1);
				return;
			}
			break;
		default:
			break;
		}
	}
}

std::vector<std::string> Split(std::string s, std::string delimiter)
{
	std::vector<std::string> result;
	size_t pos;
	std::string token;
	size_t delimiterLength = delimiter.length();

	while ((pos = s.find(delimiter)) != std::string::npos)
	{
		token = s.substr(0, pos);
		result.push_back(token);
		s.erase(0, pos + delimiterLength);
	}
	result.push_back(s);

	return result;
}

std::vector<std::vector<int>> ConvertToInt(std::vector<std::vector<std::string>> requests)
{
	std::vector<std::vector<int>> ret;
	size_t size = requests.size();
	std::vector<std::string> request;
	std::vector<int> requestInt;

	for (unsigned int i = 0; i < size; ++i)
	{
		request = requests[i];
		if (request[0].compare("withdraw") == 0)
		{
			requestInt = WithdrawConvertToInt(request);
		}
		else if (request[0].compare("transfer") == 0)
		{
			requestInt = TransferConvertToInt(request);
		}
		else if (request[0].compare("deposit") == 0)
		{
			requestInt = DepositConvertToInt(request);
		}
		else {}

		ret.push_back(requestInt);
	}
	return ret;
}

std::vector<int> WithdrawConvertToInt(std::vector<std::string> withdraw)
{
	std::vector<int> result;
	result.push_back(Withdraw);
	result.push_back(std::stoi(withdraw[1]));
	result.push_back(std::stoi(withdraw[2]));

	return result;
}

std::vector<int> TransferConvertToInt(std::vector<std::string> transfer)
{
	std::vector<int> result;
	result.push_back(Transfer);
	result.push_back(std::stoi(transfer[1]));
	result.push_back(std::stoi(transfer[2]));
	result.push_back(std::stoi(transfer[3]));
	return result;
}

std::vector<int> DepositConvertToInt(std::vector<std::string> deposit)
{
	std::vector<int> result;
	result.push_back(Deposit);
	result.push_back(std::stoi(deposit[1]));
	result.push_back(std::stoi(deposit[2]));
	return result;
}

bool WithdrawCalculate(std::vector<int> &accounts, std::vector<int> withdraw)
{
	size_t size = accounts.size();
	std::vector<int> result;
	int accountId = withdraw[1] - 1;
	int money = withdraw[2];
	if (accountId >= size || money > accounts[accountId])
	{
		return false;
	}
	accounts[accountId] = accounts[accountId] - money;
	return true;
}

bool TransferCalculate(std::vector<int> &accounts, std::vector<int> transfer)
{
	size_t size = accounts.size();
	std::vector<int> result;
	int fromId = transfer[1] - 1;
	int toid = transfer[2] - 1;
	int money = transfer[3];
	if (accounts[fromId] < money || fromId >= size || toid >= size)
	{
		return false;
	}

	accounts[fromId] = accounts[fromId] - money;
	accounts[toid] = accounts[toid] + money;
	return true;
}

bool DepositCalculate(std::vector<int> &accounts, std::vector<int> deposit)
{
	size_t size = accounts.size();
	std::vector<int> result;
	int accountId = deposit[1] - 1;
	int money = deposit[2];
	if (accountId >= size)
	{
		return false;
	}
	accounts[accountId] = accounts[accountId] + money;
	return true;
}
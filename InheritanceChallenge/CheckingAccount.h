#pragma once

#include "Account.h"

class CheckingAccount : public Account
{
	friend std::ostream& operator<<(std::ostream& os, const CheckingAccount& account);

private:
	static constexpr const char* defaultName = "Unnamed Checking Account";
	static constexpr double defaultBalance = 0.0;
	static constexpr double defaultWithdrawalFee = 1.5;

protected:
	double withdrawalFee;

public:
	CheckingAccount(std::string name = defaultName, double balance = defaultBalance, double withdrawalFee = defaultWithdrawalFee);
	bool Withdraw(double amount);
};


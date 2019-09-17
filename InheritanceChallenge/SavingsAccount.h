#pragma once

#include "Account.h"

class SavingsAccount : public Account
{
	friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& account); // Friend methods are not inherited

private:
	static constexpr const char* defaultName = "Unnamed Savings Account";
	static constexpr double defaultBalance = 0.0;
	static constexpr double defaultInterestRate = 0.0;

protected:
	double interestRate;

public:
	SavingsAccount(std::string name = defaultName, double balance = defaultBalance, double interestRate = defaultInterestRate);
	bool Deposit(double amount);
};

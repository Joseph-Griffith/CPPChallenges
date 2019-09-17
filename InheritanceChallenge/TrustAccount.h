#pragma once

#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount
{
	friend std::ostream& operator<<(std::ostream& os, const TrustAccount& account);

private:
	static constexpr const char* defaultName = "Unnamed Trust Account";
	static constexpr double defaultBalance = 0.0;
	static constexpr double defaultInterestRate = 0.0;
	static constexpr double bonus = 50.0;
	static constexpr double bonusThreshhold = 5000.0;
	static constexpr double maxWithdrawPercent = 0.2;
	static constexpr int maxNumberWithdraws = 3;

protected:
	int withdrawsThisYear{ 0 };

public:
	TrustAccount(std::string name = defaultName, double balance = defaultBalance, double interestRate = defaultInterestRate);
	bool Deposit(double amount);
	bool Withdraw(double amount);
};

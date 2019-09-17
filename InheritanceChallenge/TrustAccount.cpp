#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double interestRate)
	:SavingsAccount{ name, balance, interestRate }
{
}

bool TrustAccount::Deposit(double amount)
{
	if (amount >= bonusThreshhold)
	{
		amount += bonus;
	}

	return SavingsAccount::Deposit(amount);
}

bool TrustAccount::Withdraw(double amount)
{
	if (withdrawsThisYear < maxNumberWithdraws)
	{
		if (amount < (balance * maxWithdrawPercent))
		{
			SavingsAccount::Withdraw(amount);
			++withdrawsThisYear;
			return true;
		}
		else
		{
			std::cout << "You cannot withdraw more than " << maxWithdrawPercent * 100 << "% of your current balance at a time" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "You have reached the maximum times you can withdraw this year" << std::endl;
		return false;
	}
}

std::ostream& operator<<(std::ostream& os, const TrustAccount& account)
{
	os << "[TrustAccount: " << account.name << ": " << account.balance << ", " << account.interestRate << "% , Withdraws this year: " << account.withdrawsThisYear << "]";
	return os;
}

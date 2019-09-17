#include "Account.h"

Account::Account(std::string name, double balance)
	:name{ name }, balance{ balance }{

}

bool Account::Deposit(double amount)
{
	if (amount < 0)
	{
		return false;
	}
	else
	{
		balance += amount;
		return true;
	}
}

bool Account::Withdraw(double amount)
{
	if (balance - amount >= 0)
	{
		balance -= amount;
		return true;
	}
	else
	{
		return false;
	}
}

double Account::GetBalance() const
{
	return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account)
{
	os << "[Account: " << account.name << ": " << account.balance << "]";
	return os;
}

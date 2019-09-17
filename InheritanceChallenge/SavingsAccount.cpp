#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, double balance, double interestRate)
	:Account{ name, balance }, interestRate{ interestRate }{

}

bool SavingsAccount::Deposit(double amount)
{
	amount += amount * (interestRate / 100);
	return Account::Deposit(amount);
}

std::ostream& operator<<(std::ostream& os, const SavingsAccount& account)
{
	os << "[SavingsAccount: " << account.name << ": " << account.balance << ", " << account.interestRate << "%]";
	return os;
}

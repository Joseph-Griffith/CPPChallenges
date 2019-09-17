#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance, double withdrawalFee)
	:Account{ name, balance }, withdrawalFee{ withdrawalFee }{

}

bool CheckingAccount::Withdraw(double amount)
{
	return Account::Withdraw(amount + withdrawalFee);
}

std::ostream& operator<<(std::ostream& os, const CheckingAccount& account)
{
	os << "[CheckingAccount: " << account.name << ": " << account.balance << ", " << account.withdrawalFee << "]";
	return os;
}

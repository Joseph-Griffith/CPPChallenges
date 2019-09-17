/*
	You are provided with a simple Account class hierachy that contains
	Account - Base class
	Savings Account - Derived class

	The challenge is as follows:

	1.	Add a Checking Account class to the Account hierachy
		A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction
		Every withdrawal transaction will be assessed this flat fee

	2.	Add Trust account class to the Account hierarchy
		A Trust account has a name, a balance and an interest rate
		The Trust account deposit workd just like a savings account deposit
		However, any deposit of $5000.00 or more will recieve a $50.00 bonus to the account

		The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance
*/

#include <iostream>
#include <vector>
#include "SavingsAccount.h"
#include "AccountUtil.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

int main()
{
	std::cout.precision(2);
	std::cout << std::fixed;

	// Accounts
	std::vector<Account> accounts;
	accounts.push_back(Account{});
	accounts.push_back(Account{ "Larry" });
	accounts.push_back(Account{ "Moe", 2000 });
	accounts.push_back(Account{ "Curly", 5000 });

	Display(accounts);
	Deposit(accounts, 1000);
	Withdraw(accounts, 2000);

	// Savings Account
	std::vector<SavingsAccount> savAccounts;
	savAccounts.push_back(SavingsAccount{});
	savAccounts.push_back(SavingsAccount{ "Superman" });
	savAccounts.push_back(SavingsAccount{ "Batman", 2000 });
	savAccounts.push_back(SavingsAccount{ "Wonderwoman", 5000, 5.0 });

	Display(savAccounts);
	Deposit(savAccounts, 1000);
	Withdraw(savAccounts, 2000);

	// Checking Account
	std::vector<CheckingAccount> checkAccounts;
	checkAccounts.push_back(CheckingAccount{});
	checkAccounts.push_back(CheckingAccount{ "Kirk" });
	checkAccounts.push_back(CheckingAccount{ "Spock", 2000 });
	checkAccounts.push_back(CheckingAccount{ "Bones", 5000 });

	Display(checkAccounts);
	Deposit(checkAccounts, 1000);
	Withdraw(checkAccounts, 2000);

	// Checking Account
	std::vector<TrustAccount> trustAccounts;
	trustAccounts.push_back(TrustAccount{});
	trustAccounts.push_back(TrustAccount{ "Athos", 10000, 5.0 });
	trustAccounts.push_back(TrustAccount{ "Porthos", 20000, 4.0 });
	trustAccounts.push_back(TrustAccount{ "Aramis", 30000 });

	Display(trustAccounts);
	Deposit(trustAccounts, 1000);
	Withdraw(trustAccounts, 3000);

	// Withdraw 5 times from each trust account
	// All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
	for (int i = 0; i < 5; i++)
	{
		Withdraw(trustAccounts, 1000);
	}
}
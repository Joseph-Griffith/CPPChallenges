/*
	This challenge follows on from the Inheritance Challenge

	Your challenge is the following:

	1. Modify the Account class so it is now an Abstract class by adding the following pure virtual functions:
		virtual bool Deposit(double amount) = 0;
		virtual bool Withdraw(double amount) = 0;

		Hint: You can implement these functions in the Account class if it makes sense

	2. Create an IPrintable class interface as we did in the course and provide functionality so all accounts are printable
		to an ostream using the overloaded insertion operator

		class IPrintable
		{
			friend std::ostream& operator<<(std::ostream& os, const IPrintable& obj);

		public:
			virtual void Print(std::ostream& os) const = 0;

			virtual~IPrintable() = default;
		};

	3. Modify the functions in the AccountUtil files so we only have one version of each.

	4. Test your code with Base class pointers as well as local objects
*/

#include <iostream>
#include <vector>
#include "Account.h"
#include "Savings_Account.h"
#include "Checking_Account.h"
#include "Trust_Account.h"
#include "Account_Util.h"


int main()
{
	Checking_Account c;
	std::cout << c << std::endl;

	Savings_Account s{ "Frank", 5000, 2.6 };
	std::cout << s << std::endl;
	s.deposit(10000);
	std::cout << s << std::endl;
	s.withdraw(10000);
	std::cout << s << std::endl;

	Account* ptr = new Trust_Account("Leo", 10000, 2.6);
	std::cout << *ptr << std::endl;

	// Savings 

	Account* s1 = new Savings_Account{};
	Account* s2 = new Savings_Account{ "Superman" };
	Account* s3 = new Savings_Account{ "Batman", 2000 };
	Account* s4 = new Savings_Account{ "Wonderwoman", 5000, 5.0 };

	std::vector<Account*> sav_accounts;
	sav_accounts.push_back(s1);
	sav_accounts.push_back(s2);
	sav_accounts.push_back(s3);
	sav_accounts.push_back(s4);

	display(sav_accounts);
	deposit(sav_accounts, 1000);
	withdraw(sav_accounts, 2000);

	// Checking

	Account* c1 = new Checking_Account{};
	Account* c2 = new Checking_Account{ "Kirk" };
	Account* c3 = new Checking_Account{ "Spock", 2000 };
	Account* c4 = new Checking_Account{ "Bones", 5000 };

	std::vector<Account*> check_accounts;
	check_accounts.push_back(c1);
	check_accounts.push_back(c2);
	check_accounts.push_back(c3);
	check_accounts.push_back(c4);

	display(check_accounts);
	deposit(check_accounts, 1000);
	withdraw(check_accounts, 2000);

	// Trust

	Account* t1 = new Trust_Account{};
	Account* t2 = new Trust_Account{ "Athos", 10000, 5.0 };
	Account* t3 = new Trust_Account{ "Porthos", 20000, 4.0 };
	Account* t4 = new Trust_Account{ "Aramis", 30000 };

	std::vector<Account*> trust_accounts;
	trust_accounts.push_back(t1);
	trust_accounts.push_back(t2);
	trust_accounts.push_back(t3);
	trust_accounts.push_back(t4);

	display(trust_accounts);
	deposit(trust_accounts, 1000);
	withdraw(trust_accounts, 3000);

	// Withdraw 5 times from each trust account
	// All withdrawals should fail if there are too many withdrawals or if the withdrawl is > 20% of the balance
	for (int i = 1; i <= 5; i++)
		withdraw(trust_accounts, 1000);

	delete s1;
	delete s2;
	delete s3;
	delete s4;
	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete t1;
	delete t2;
	delete t3;
	delete t4;
}
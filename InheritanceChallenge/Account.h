#pragma once

#include <iostream>
#include<string>

class Account
{
	friend std::ostream& operator<<(std::ostream& os, const Account& account);

private:
	static constexpr const char* defaultName = "Unnamed Account";
	static constexpr double defaultBalance = 0.0;

protected:
	std::string name;
	double balance;

public:
	Account(std::string = defaultName, double = defaultBalance);
	bool Deposit(double amount);
	bool Withdraw(double amount);
	double GetBalance() const;
};

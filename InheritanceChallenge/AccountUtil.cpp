#include "AccountUtil.h"
#include <iostream>

// Helper functions for Account class

// Displays Account objects in a vector of Account objects
void Display(const std::vector<Account>& accounts)
{
	std::cout << "\n=== Accounts =======================================" << std::endl;
	for (const auto& acc : accounts)
	{
		std::cout << acc << std::endl;
	}
}

// Deposits supplied amount for each Account object in the vector
void Deposit(std::vector<Account>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Accounts =========================" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit the amount of " << amount << " to " << acc << std::endl;
	}
}

// Withdraw amount from each Account object in the vector
void Withdraw(std::vector<Account>& accounts, double amount)
{
	std::cout << "\n=== Withdrawing from Accounts ======================" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}

// Helper functions for Savings Account class

// Displays Savings Account objects in a vector of Savings Account objects
void Display(const std::vector<SavingsAccount>& accounts)
{
	std::cout << "\n=== Savings Accounts ===============================" << std::endl;
	for (const auto& acc : accounts)
	{
		std::cout << acc << std::endl;
	}
}

// Deposits supplied amount for each Savings Account object in the vector
void Deposit(std::vector<SavingsAccount>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Savings Accounts =================" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit the amount of " << amount << " to " << acc << std::endl;
	}
}

// Withdraw amount from each Savings Account object in the vector
void Withdraw(std::vector<SavingsAccount>& accounts, double amount)
{
	std::cout << "\n=== Withdrawing from Savings Accounts ==============" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}

// Helper functions for Checking Account class

// Displays Checking Account objects in a vector of Checking Account objects
void Display(const std::vector<CheckingAccount>& accounts)
{
	std::cout << "\n=== Checking Accounts ===============================" << std::endl;
	for (const auto& acc : accounts)
	{
		std::cout << acc << std::endl;
	}
}

// Deposits supplied amount for each Checking Account object in the vector
void Deposit(std::vector<CheckingAccount>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Checking Accounts =================" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit the amount of " << amount << " to " << acc << std::endl;
	}
}

// Withdraw amount from each Checking Account object in the vector
void Withdraw(std::vector<CheckingAccount>& accounts, double amount)
{
	std::cout << "\n=== Withdrawing from Checking Accounts ==============" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}

// Helper functions for Trust Account class

// Displays Trust Account objects in a vector of Trust Account objects
void Display(const std::vector<TrustAccount>& accounts)
{
	std::cout << "\n=== Trust Accounts =======================================" << std::endl;
	for (const auto& acc : accounts)
	{
		std::cout << acc << std::endl;
	}
}

// Deposits supplied amount for each Trust Account object in the vector
void Deposit(std::vector<TrustAccount>& accounts, double amount)
{
	std::cout << "\n=== Depositing to Trust Accounts =========================" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Deposit(amount))
			std::cout << "Deposited " << amount << " to " << acc << std::endl;
		else
			std::cout << "Failed to deposit the amount of " << amount << " to " << acc << std::endl;
	}
}

// Withdraw amount from each Trust Account object in the vector
void Withdraw(std::vector<TrustAccount>& accounts, double amount)
{
	std::cout << "\n=== Withdrawing from Trust Accounts ======================" << std::endl;
	for (auto& acc : accounts)
	{
		if (acc.Withdraw(amount))
			std::cout << "Withdrew " << amount << " from " << acc << std::endl;
		else
			std::cout << "Failed withdrawal of " << amount << " from " << acc << std::endl;
	}
}

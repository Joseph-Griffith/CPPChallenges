#pragma once

#include <vector>
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"

// Utility helper functions for Account class
void Display(const std::vector<Account>& accounts);
void Deposit(std::vector<Account>& accounts, double amount);
void Withdraw(std::vector<Account>& accounts, double amount);

// Utility helper functions for Savings Account class
void Display(const std::vector<SavingsAccount>& accounts);
void Deposit(std::vector<SavingsAccount>& accounts, double amount);
void Withdraw(std::vector<SavingsAccount>& accounts, double amount);

// Utility helper functions for Checking Account class
void Display(const std::vector<CheckingAccount>& accounts);
void Deposit(std::vector<CheckingAccount>& accounts, double amount);
void Withdraw(std::vector<CheckingAccount>& accounts, double amount);

// Utility helper functions for Trust Account class
void Display(const std::vector<TrustAccount>& accounts);
void Deposit(std::vector<TrustAccount>& accounts, double amount);
void Withdraw(std::vector<TrustAccount>& accounts, double amount);

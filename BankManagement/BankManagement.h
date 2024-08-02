#pragma once
#include "InputOutput.h"



bool UserInteraction();

class BankAccount
{
public:
	BankAccount(std::string accountName, double amount) : name(accountName), balance(amount) {}

	void Deposit(double amount);
	void Withdraw(double amount);
	void DisplayBalance();

private:
	double balance;
	std::string name;
};
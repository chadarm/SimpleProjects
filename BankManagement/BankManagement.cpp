// BankManagement.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "BankManagement.h"

int main()
{
    bool running = true;
    do
    {
        running = UserInteraction();
    } while (running);
    return 0;
}

bool UserInteraction()
{
    std::string name;
    double initialDeposit;

    name = GetStringInput("Enter your name:\n");
    initialDeposit = GetDoubleInput("Enter initial deposit:\n");

    BankAccount account(name, initialDeposit);

    int choice;
    double amount;

    do
    {
        PromptUser("\n1. Deposit");
        PromptUser("2. Withdraw");
        PromptUser("3. Display Account");
        PromptUser("4. Exit");
        choice = GetIntInput("Enter choice: ");

        switch (choice)
        {
        case 1:
            amount = GetDoubleInput("Enter deposit amount: ");
            account.Deposit(amount);
            break;
        case 2:
            amount = GetDoubleInput("Enter withdrawal amount: ");
            account.Withdraw(amount);
            break;
        case 3:
            account.DisplayBalance();
            break;
        case 4:
            break;
        default:
            PromptUser("Invalid choice.");
        }
    } while (choice != 4);

    return 0;
}

void BankAccount::Deposit(double amount)
{
    balance += amount;
}

void BankAccount::Withdraw(double amount)
{
    if (amount <= balance)
    {
        balance -= amount;
    }
    else
    {
        PromptUser("Insufficient funds.");
    }
}

void BankAccount::DisplayBalance()
{
    PromptUser("Hello, " + name + "\n");
    PromptUser("Your Account Balance is: \n");
    PromptUser("$" + std::to_string(balance));
}

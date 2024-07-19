// Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


#include "Calculator.h"

int main()
{
    bool running = true;
    do
    {
        running = UserInteraction();
    } while (running);
}


bool UserInteraction()
{
    double num1, num2;
    char operation, keepGoing;

    try
    {
        num1 = GetDoubleInput("Enter first number: ");
        num2 = GetDoubleInput("Enter second number: ");
        operation = GetCharInput("Enter an operation (+, -, *, /): ", "+-*/");

        PrintResult(num1, num2, operation);

        keepGoing = GetCharInput("Would you like to keep calculating? (y=yes, n=no)", "yn");
        
    }
    catch (std::exception e)
    {
        std::cout << "Whoops, invalid input.";
        keepGoing = GetCharInput("Would you like to keep calculating? (y=yes, n=no)", "yn");
    }

    return (keepGoing=='y');
}

void PrintResult(double num1, double num2, char operation)
{
    switch (operation)
    {
        case '+':
            std::cout << "Result: " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "Result: " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "Result: " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 != 0)
            {
                std::cout << "Result: " << num1 / num2 << std::endl;
            }
            else
            {
                std::cout << "Error: Division by zero" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation" << std::endl;
    }
}




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

double GetDoubleInput(std::string prompt)
{
    double input = -1;
    while (true)
    {
        std::cout << prompt;
        std::cin >> input;

        if (!std::cin)
        {
            std::cin.clear();
            IgnoreRestOfInput();
            continue;
        }

        IgnoreRestOfInput();
        return input;
    }
}

char GetCharInput(std::string prompt, std::string acceptableChars)
{
    char input = '\n';
    while (true)
    {
        std::cout << prompt;
        std::cin >> input;

        bool charAccepted = false;
        for (int i = 0; i<acceptableChars.size(); i++)
        {
            if (acceptableChars[i] == input)
            {
                charAccepted = true;
            }
        }

        if (!std::cin || !charAccepted)
        {
            std::cin.clear();
            IgnoreRestOfInput();
            continue;
        }


        IgnoreRestOfInput();
        return input;
    }
}

void IgnoreRestOfInput()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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




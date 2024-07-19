#pragma once
#include "InputOutput.h"


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

int GetIntInput(std::string prompt)
{
    int input = -1;
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
        for (int i = 0; i < acceptableChars.size(); i++)
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
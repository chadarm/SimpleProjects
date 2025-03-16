// DiceRoller.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DiceRoller.h"

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
    int dice;
    char keepGoing;

    try
    {
        dice = GetIntInput("Enter dice maximum: ");

        std::string diceResult = RollDice(dice);
        PromptUser("You rolled a " + diceResult + "!");

        keepGoing = GetCharInput("Would you like to keep calculating? (y=yes, n=no)", "yn");

    }
    catch (std::exception e)
    {
        PromptUser("Whoops, invalid input.");
        keepGoing = GetCharInput("Would you like to keep calculating? (y=yes, n=no)", "yn");
    }

    return (keepGoing == 'y');
}

std::string RollDice(int diceMaximum)
{
    return std::to_string(GetRandomInt(diceMaximum));
}

// Gets number betweeen 1 and Upperbound Parameter
int GetRandomInt(int upperBound)
{
    std::srand(std::time({}));
    return (1 + rand() % upperBound);
}

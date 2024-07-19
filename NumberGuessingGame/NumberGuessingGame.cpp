// NumberGuessingGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

#include "NumberGuessingGame.h"

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
    bool keepGoing = false;

    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;

    std::cout << "I have chosen a number between 1 and 100." << std::endl;
    std::cout << "Can you guess what it is?" << std::endl;

    while (guess != secretNumber)
    {
        guess = GetIntInput("Enter your guess: ");

        if (guess > secretNumber)
        {
            std::cout << "Too high! Try again." << std::endl;
        }
        else if (guess < secretNumber)
        {
            std::cout << "Too low! Try again." << std::endl;
        }
        else
        {
            std::cout << "Congratulations! You guessed my number!" << std::endl;
            keepGoing = GetCharInput("Would you like to play again? (y=yes, n=no)", "yn");

        }
    }

    return (keepGoing=='y');
}





// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "TicTacToe.h"

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
    TicTacToeBoard game;
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    while (!gameOver)
    {
        game.DrawBoard();
        std::cout << "Player " << currentPlayer << ", ";
        row = (GetCharInput("Enter a row(0-2): ", "012") - '0');
        col = (GetCharInput("Enter a column(0-2): ", "012") - '0');


        if (!game.IsSpaceTaken(row, col))
        {
            game.AddToSpace(currentPlayer, row, col);
            gameOver = game.HasWon(currentPlayer);

            if (gameOver)
            {
                game.DrawBoard();
                std::cout << "Player " << currentPlayer << " wins!" << std::endl;
            }
            else if (game.HasGameEndedInDraw())
            {
                game.DrawBoard();
                PromptUser("It's a draw!");
                gameOver = true;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
        else
        {
            PromptUser("That spot is already taken. Try again.");
        }
    }

    return false;
}


void TicTacToeBoard::DrawBoard()
{
    PromptUser("Current Game Board:");
    for (const auto& row : gameBoard)
    {
        for (char cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

bool TicTacToeBoard::HasWon(char player)
{
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; ++i)
    {
        if ((gameBoard[i][0] == player && gameBoard[i][1] == player && gameBoard[i][2] == player) ||
            (gameBoard[0][i] == player && gameBoard[1][i] == player && gameBoard[2][i] == player))
        {
            return true;
        }
    }

    if ((gameBoard[0][0] == player && gameBoard[1][1] == player && gameBoard[2][2] == player) ||
        (gameBoard[0][2] == player && gameBoard[1][1] == player && gameBoard[2][0] == player))
    {
        return true;
    }

    return false;
}

// If all spaces taken, draw
bool TicTacToeBoard::HasGameEndedInDraw()
{
    for (const auto& row : gameBoard)
    {
        for (char cell : row)
        {
            if (cell == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

// Returns true is the space is occupied
bool TicTacToeBoard::IsSpaceTaken(int row, int col)
{
    return !(gameBoard[row][col] == ' ');
}

void TicTacToeBoard::AddToSpace(char player, int row, int col)
{
    gameBoard[row][col] = player;
}

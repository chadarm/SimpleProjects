#pragma once

#include "InputOutput.h"
#include <vector>

typedef std::vector<std::vector<char>> board;

bool UserInteraction();

class TicTacToeBoard
{
public:
	TicTacToeBoard()
	{
		gameBoard = board(3, std::vector<char>(3, ' '));
	}

	void DrawBoard();
	bool HasWon(char player);
	bool HasGameEndedInDraw();
	bool IsSpaceTaken(int row, int col);
	void AddToSpace(char player, int row, int col);

private:
	board gameBoard;
};
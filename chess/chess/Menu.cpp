#include "Menu.h"
#include "Rook.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
Menu::Menu()
{
	this->_numOfMoves = 0;
}

void createBoard(std::vector<std::vector<Piece*>>& board)
{
	int x = 0;
	int y = 0;
	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		for (x = 0; x < BOARD_WIDTH; x++)
		{
			board[y][x] = nullptr;
		}
	}
	
}

void addPiecesToBoard(std::vector<std::vector<Piece*>>& board)
{
	
}

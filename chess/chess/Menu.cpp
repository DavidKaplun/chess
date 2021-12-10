#include "Menu.h"
#include "Rook.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
Menu::Menu()
{
	this->_numOfMoves = 0;
	createBoard(this->_board);
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
	//white rooks
	board[7][0]=new Rook('a','1','r','w');
	board[7][7] = new Rook('h', '1', 'r', 'w');

	//black rooks
	board[0][0] = new Rook('a', '8', 'r', 'b');
	board[0][7] = new Rook('h', '8', 'r', 'b');

	//white knights
}

#include "Menu.h"

//da big guys
#include "King.h"
#include "Queen.h"
//da medium guys
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
//just a small pawn
#include "Pawn.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

void createBoard(std::vector<std::vector<Piece*>>& board);
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
	board[7][0] = new Rook('a', '1', 'r', 'w');
	board[7][7] = new Rook('h', '1', 'r', 'w');

	//black rooks
	board[0][0] = new Rook('a', '8', 'r', 'b');
	board[0][7] = new Rook('h', '8', 'r', 'b');


	//white knights
	board[7][1] = new Knight('b', '1', 'n', 'w');
	board[7][6] = new Knight('g', '1', 'n', 'w');

	//black knights
	board[0][1] = new Knight('b', '8', 'n', 'b');
	board[0][6] = new Knight('g', '8', 'n', 'b');


	//white bishops
	board[7][2] = new Knight('c', '1', 'b', 'w');
	board[7][5] = new Knight('f', '1', 'b', 'w');

	//black bishops
	board[0][2] = new Knight('c', '8', 'b', 'b');
	board[0][5] = new Knight('f', '8', 'b', 'b');
}

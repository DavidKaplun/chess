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
void addPiecesToBoard(std::vector<std::vector<Piece*>>& board);
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
	addPiecesToBoard(board);
	
}

void addPiecesToBoard(std::vector<std::vector<Piece*>>& board)
{
	//black rooks
	board[7][0] = new Rook('a', '8', 'r', 'b');
	board[7][7] = new Rook('h', '8', 'r', 'b');

	//white rooks
	board[0][0] = new Rook('a', '1', 'r', 'w');
	board[0][7] = new Rook('h', '1', 'r', 'w');


	//black knights
	board[7][1] = new Knight('b', '8', 'n', 'b');
	board[7][6] = new Knight('g', '8', 'n', 'b');

	//white knights
	board[0][1] = new Knight('b', '1', 'n', 'w');
	board[0][6] = new Knight('g', '1', 'n', 'w');


	//black bishops
	board[7][2] = new Bishop('c', '8', 'b', 'b');
	board[7][5] = new Bishop('f', '8', 'b', 'b');

	//white bishops
	board[0][2] = new Bishop('c', '1', 'b', 'w');
	board[0][5] = new Bishop('f', '1', 'b', 'w');


	//black queen
	board[7][3] = new Queen('d', '8', 'q', 'b');

	//white queen
	board[0][3] = new Queen('d', '1', 'q', 'w');

	
	//black king
	board[7][4] = new King('e', '8', 'k', 'b');

	//white king
	board[0][4] = new King('e', '1', 'k', 'w');
}

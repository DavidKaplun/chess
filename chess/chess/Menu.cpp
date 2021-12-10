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


Menu::Menu()
{
	this->_numOfMoves = 0;
	createBoard(this->_board);
}

void printBoard(std::vector<std::vector<Piece*>>& board)
{
	int x = 0;
	int y = 0;
	
	for (y = 0; y < BOARD_WIDTH; y++)
	{
		for (x = 0; x < BOARD_HEIGHT; x++)
		{
			if (board[y][x] == nullptr)
			{
				std::cout << "#";
			}
			else
			{
				std::cout << board[y][x]->getType();
			}
		}
		std::cout << std::endl;

	}

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
	board[7][0] = new Rook('r', 'b');
	board[7][7] = new Rook('r', 'b');

	//white rooks
	board[0][0] = new Rook('r', 'w');
	board[0][7] = new Rook('r', 'w');


	//black knights
	board[7][1] = new Knight('n', 'b');
	board[7][6] = new Knight('n', 'b');

	//white knights
	board[0][1] = new Knight('n', 'w');
	board[0][6] = new Knight('n', 'w');


	//black bishops
	board[7][2] = new Bishop('b', 'b');
	board[7][5] = new Bishop('b', 'b');

	//white bishops
	board[0][2] = new Bishop('b', 'w');
	board[0][5] = new Bishop('b', 'w');


	//black queen
	board[7][3] = new Queen('q', 'b');

	//white queen
	board[0][3] = new Queen('q', 'w');

	
	//black king
	board[7][4] = new King('k', 'b');

	//white king
	board[0][4] = new King('k', 'w');
}

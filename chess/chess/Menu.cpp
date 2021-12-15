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
	createBoard();
}

std::vector<std::vector<Piece*>>& Menu::getBoard()
{
	return this->_board;
}


void Menu::updateBoard(std::string move)
{
	Piece* pieceToDelete;
	int source_x = move[0] - 97;
	int source_y = 7-(move[1] - 49);

	int destination_x = move[2] - 97;
	int destination_y = 7-(move[3] - 49);
	
	
	if (this->_board[destination_y][destination_x] != nullptr)
	{
		pieceToDelete = this->_board[destination_y][destination_x];
		pieceToDelete->deletePiece();
	}
	this->_board[destination_y][destination_x] = this->_board[source_y][source_x];
	this->_board[source_y][source_x] = nullptr;
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
				std::cout << "# ";
			}
			else
			{
				std::cout << board[y][x]->getType()<<" ";
			}
		
		}
		std::cout << std::endl;

	}

}
void Menu::createBoard()
{
	int x = 0;
	int y = 0;
	std::vector<Piece*> row;
	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		for (x = 0; x < BOARD_WIDTH; x++)
		{
			row.push_back(nullptr);
		}
		_board.push_back(row);
	}
	addPiecesToBoard();
	
}

void Menu::addPiecesToBoard()
{

	//black rooks
	_board[0][0] = new Rook('r', 'b');
	_board[0][7] = new Rook('r', 'b');

	//white rooks
	_board[7][0] = new Rook('R', 'w');
	_board[7][7] = new Rook('R', 'w');


	//black knights
	_board[0][1] = new Knight('n', 'b');
	_board[0][6] = new Knight('n', 'b');

	//white knights
	_board[7][1] = new Knight('N', 'w');
	_board[7][6] = new Knight('N', 'w');


	//black bishops
	_board[0][2] = new Bishop('b', 'b');
	_board[0][5] = new Bishop('b', 'b');

	//white bishops
	_board[7][2] = new Bishop('B', 'w');
	_board[7][5] = new Bishop('B', 'w');


	//black queen
	_board[0][3] = new Queen('q', 'b');

	//white queen
	_board[7][3] = new Queen('Q', 'w');

	
	//white king
	this->_whiteKing = new King('K', 'w');
	this->_whiteKing->setX(4);
	this->_whiteKing->setY(7);
	_board[7][4] = this->_whiteKing;
	
	//black king
	this->_blackKing = new King('k', 'b');
	this->_blackKing->setX(4);
	this->_blackKing->setY(0);
	_board[0][4] = this->_blackKing;

	int x = 0;
	for (x = 0; x < BOARD_WIDTH; x++)
	{
		_board[6][x] = new Pawn('P', 'w');//sets up the white pawns
		_board[1][x] = new Pawn('p', 'b');
	}
	
}

void Menu::incNumOfMoves()
{
	this->_numOfMoves++;
}

int Menu::getNumOfMoves() 
{
	return this->_numOfMoves;
}

King* Menu::getWhiteKing()
{
	return this->_whiteKing;
}

King* Menu::getBlackKing()
{
	return this->_blackKing;
}

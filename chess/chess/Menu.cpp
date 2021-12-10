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

std::vector<std::vector<Piece*>>& Menu::getBoard()
{
	return this->_board;
}


void Menu::updateBoard(std::string move)
{
	int source_x = move[0] - 97;
	int source_y = move[1] - 48;

	int destination_x = move[2] - 97;
	int destination_y = move[3] - 48;

	if (this->_board[source_y][source_x] == nullptr)
	{
		std::cout << "You can't move because there is no piece in this square" << std::endl;
	}
	else if(this->_board[destination_y][destination_x]==nullptr)
	{
		if (this->_board[source_y][source_x]->getColor() == this->_board[destination_y][destination_x]->getColor())
		{
			std::cout << "You can't eat a piece thats on your team" << std::endl;
		}
	}
	else
	{
		this->_board[source_y][source_x]->isMovePossible(source_x,source_y,destination_x,destination_y,this->_board);
	}
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
void createBoard(std::vector<std::vector<Piece*>>& board)
{
	int x = 0;
	int y = 0;
	std::vector<Piece*> row;
	for (y = 0; y < BOARD_HEIGHT; y++)
	{
		//board.push_back(new std::vector<Piece*>);
		for (x = 0; x < BOARD_WIDTH; x++)
		{
			row.push_back(nullptr);
			//board[y].push_back(nullptr);
		}
		board.push_back(row);
	}
	addPiecesToBoard();
	
}

void Menu::addPiecesToBoard()
{

	//black rooks
	_board[7][0] = new Rook('r', 'b');
	_board[7][7] = new Rook('r', 'b');

	//white rooks
	_board[0][0] = new Rook('R', 'w');
	_board[0][7] = new Rook('R', 'w');


	//black knights
	_board[7][1] = new Knight('n', 'b');
	_board[7][6] = new Knight('n', 'b');

	//white knights
	_board[0][1] = new Knight('N', 'w');
	_board[0][6] = new Knight('N', 'w');


	//black bishops
	_board[7][2] = new Bishop('b', 'b');
	_board[7][5] = new Bishop('b', 'b');

	//white bishops
	_board[0][2] = new Bishop('B', 'w');
	_board[0][5] = new Bishop('B', 'w');


	//black queen
	_board[7][3] = new Queen('q', 'b');

	//white queen
	_board[0][3] = new Queen('Q', 'w');

	
	//black king
	_board[7][4] = new King('k', 'b');
	this->_blackKing = _board[7][4];
	//white king
	_board[0][4] = new King('K', 'w');
	this->_whiteKing = _board[0][4];
}

void Menu::incNumOfMoves()
{
	this->_numOfMoves++;
}


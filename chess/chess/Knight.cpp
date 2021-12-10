#include "Knight.h"

Knight::Knight(char x, char y, char type, char color):Piece(x,y,type,color)
{
	this->_posX = x;
	this->_posY = y;
	this->_type = type;
	this->_color = color;
}

Knight::~Knight()
{

}

void Knight::change_pos_moves(std::vector<std::vector<Piece*>> board)
{
	int current_x = int(this->_posX) - 97;
	int current_y = int(this->_posY) - 48;
	// e7
	// current_x = 101-97 = 4
	// board[8-current_x = 4] = e
	// current_y = 55-48 = 7
	// board[8-current_x = 1] = 7      
	/*
	8 - 0
	7 - 1
	6 - 2
	5 - 3
	4 - 4
	3 - 5
	2 - 6
	1 - 7
	*/
}
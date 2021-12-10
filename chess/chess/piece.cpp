#include "piece.h"

Piece::Piece(char y, char x, char type, char color)
{
	move(y, x);
	this->_type = type;
	this->_color = color;

}

Piece::~Piece()
{
	// no allocated memory
}

void Piece::move(char y, char x)
{
	this->_posX = x;
	this->_posY = y;
}

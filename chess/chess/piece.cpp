#include "piece.h"

Piece::Piece(char x, char y, char type, char color)
{
	move(x, y);
	this->_type = type;
	this->_color = color;

}

Piece::~Piece()
{
	// no allocated memory
}

void Piece::move(char x, char y)
{
	this->_posX = x;
	this->_posY = y;
}

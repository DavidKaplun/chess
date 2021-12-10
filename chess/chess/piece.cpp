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



char Piece::getType()
{
	return this->_type;
}

char Piece::getColor()
{
	return this->_color;
}
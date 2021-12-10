#include "piece.h"

Piece::Piece(char type, char color)
{
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
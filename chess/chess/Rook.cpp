#include "Rook.h"

Rook::Rook(char x, char y, char type, char color) : Piece(x,y,type,color)
{
	this->_isFirstMove = true;
}

Rook::~Rook()
{
	//no allocated memory
}


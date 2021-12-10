#include "Rook.h"

Rook::Rook(char type, char color) : Piece(type,color)
{
	this->_isFirstMove = true;
}

Rook::~Rook()
{
	//no allocated memory
}


#include "Rook.h"

Rook::Rook(char type, char color) : Piece(type,color)
{
	this->_isFirstMove = true;
}

Rook::~Rook()
{
	//no allocated memory
}

bool Rook::isMovePossible(int source_x, int source_y, int destination_x, int destination_y)
{
	if (source_x != destination_x and source_y!=destination_y)
	{
		return false;
	}

}
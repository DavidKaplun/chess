#include "Pawn.h"

Pawn::Pawn(char type, char color) :Piece(type, color)
{
	this->_isFirstMove = true;
}

Pawn::~Pawn()
{

}

bool Pawn::isMovePossible(int source_x, int source_y, int destination_x, int destination_y)
{
	return 1;
}

#include "Pawn.h"

Pawn::Pawn(char type, char color) :Piece(type, color)
{
	this->_isFirstMove = true;
}

Pawn::~Pawn()
{

}

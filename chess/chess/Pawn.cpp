#include "Pawn.h"

Pawn::Pawn(char x, char y, char type, char color) :Piece(x, y, type, color)
{
	this->_isFirstMove = true;
}

Pawn::~Pawn()
{

}

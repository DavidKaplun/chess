#include "Bishop.h"

Bishop::Bishop(char type, char color) :Piece(type, color)
{

}

Bishop::~Bishop()
{

}

bool Bishop::isMovePossible(int source_x, int source_y, int destination_x, int destination_y)
{
	return 1;
}


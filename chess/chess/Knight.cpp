#include "Knight.h"

Knight::Knight(char type, char color):Piece(type,color)
{
	
}

Knight::~Knight()
{

}

bool Knight::isMovePossible(int source_x, int source_y, int destination_x, int destination_y)
{
	return 1;
}

#include "Knight.h"

Knight::Knight(char type, char color):Piece(type,color)
{
	
}

Knight::~Knight()
{

}

bool Knight::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	return 1;
}

void Knight::deletePiece()
{
	this->~Knight();
}
#include "Queen.h"

Queen::Queen(char type, char color) :Piece(type,color)
{

}

Queen::~Queen()
{

}

bool Queen::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	return 1;
}

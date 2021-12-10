#include "Bishop.h"

Bishop::Bishop(char type, char color) :Piece(type, color)
{

}

Bishop::~Bishop()
{

}

bool Bishop::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	if (source_x - destination_x != source_y - destination_y)
	{
		return false;
	}
}


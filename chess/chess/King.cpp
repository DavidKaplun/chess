#include "King.h"

King::King(char type, char color) :Piece(type, color)
{

}

King::~King()
{

}

bool King::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	//isInDangerAfterMove(destination_x,destination_y)
	return 1;
}

bool King::isInDangerAfterMove(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	return true;
}

bool King::isInCheckFromRook(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	return true;
}
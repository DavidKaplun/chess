#include "Rook.h"

Rook::Rook(char type, char color) : Piece(type,color)
{
	this->_isFirstMove = true;
}

Rook::~Rook()
{
	//no allocated memory
}

bool Rook::isMovePossible(int source_x, int source_y, int destination_x, int destination_y,std::vector<std::vector<Piece*>> board)
{
	if (source_x == destination_x and source_y==destination_y)
	{
		return false;
	}

	int i = 0;
	if (source_x == destination_x)
	{
		bool isPlus = source_y < destination_y;
		int difference = abs(source_y - destination_y);
		for (i = 0; i < difference; i++)
		{
			if (isPlus)
			{
				if (board[source_y + i][source_x] != nullptr)
				{
					return false;
				}
			}
			else
			{
				if (board[source_y - i][source_x] != nullptr)
				{
					return false;
				}
			}
			
		}
	}
	else
	{
		bool isPlus = source_x < destination_x;
		int difference = abs(source_x - destination_x);
		for (i = 0; i < difference; i++)
		{
			if (isPlus)
			{
				if (board[source_y][source_x+i] != nullptr)
				{
					return false;
				}
			}
			else
			{
				if (board[source_y][source_x - i] != nullptr)
				{
					return false;
				}
			}
			
		}
	}
	return true;
}
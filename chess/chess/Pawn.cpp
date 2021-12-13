#include "Pawn.h"

Pawn::Pawn(char type, char color) :Piece(type, color)
{
	this->_isFirstMove = true;
}

Pawn::~Pawn()
{

}

bool Pawn::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	if (this->getColor() == 'w')
	{
		if (destination_y == source_y + 1 and source_x == destination_x)
		{
			if (board[destination_y][destination_x] == nullptr)
			{
				this->_isFirstMove = false;
				return true;
			}
			else
			{
				return false;
			}
		}
		else if(this->_isFirstMove==true and destination_y==source_y+2 and source_x==destination_x)
		{
			if (board[destination_y][destination_x] == nullptr and board[destination_y - 1][destination_x] == nullptr)
			{
				this->_isFirstMove = false;
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (destination_y == source_y + 1 and abs(source_x - destination_x) == 1)
		{
			if (board[destination_y][destination_x] != nullptr)
			{
				if (board[destination_y][destination_x]->getColor() != this->getColor())
				{
					this->_isFirstMove = false;
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return false;
	}

	else if (this->getColor() == 'b')
	{
		if (destination_y == source_y - 1 and source_x == destination_x)
		{
			if (board[destination_y][destination_x] == nullptr)
			{
				this->_isFirstMove = false;
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (this->_isFirstMove == true and destination_y == source_y - 2 and source_x == destination_x)
		{
			if (board[destination_y][destination_x] == nullptr and board[destination_y + 1][destination_x] == nullptr)
			{
				this->_isFirstMove = false;
				return true;
			}
			else
			{
				return false;
			}
		}
		else if (destination_y == source_y - 1 and abs(source_x - destination_x) == 1)
		{
			if (board[destination_y][destination_x] != nullptr)
			{
				if (board[destination_y][destination_x]->getColor() != this->getColor())
				{
					this->_isFirstMove = false;
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return false;
			}
		}
		return false;
	}
}

void Pawn::deletePiece()
{
	this->~Pawn();
}

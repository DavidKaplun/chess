#include "Bishop.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8
Bishop::Bishop(char type, char color) :Piece(type, color)
{

}

Bishop::~Bishop()
{

}

bool Bishop::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	if (abs(source_x - destination_x) != abs(source_y - destination_y))
	{
		return false;
	}
	
	int x, y;
	if (destination_x > source_x and destination_y > source_y)
	{


		x = source_x + 1;
		y = source_y + 1;
		while (x < BOARD_WIDTH and y < BOARD_HEIGHT)
		{
			if (x == destination_x and y == destination_y)
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					std::cout << "Bishops can't jump over pieces" << std::endl;
					return false;
				}
			}
			x++;
			y++;
		}
	}

	else if (destination_x > source_x and destination_y < source_y)
	{


		x = source_x + 1;
		y = source_y - 1;
		while (x < BOARD_WIDTH and 0<=y)
		{
			if (x == destination_x and y == destination_y)
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					std::cout << "Bishops can't jump over pieces" << std::endl;
					return false;
				}
			}
			x++;
			y--;
		}
	}

	else if (destination_x < source_x and destination_y > source_y)
	{


		x = source_x - 1;
		y = source_y + 1;
		while (0<=x and y < BOARD_HEIGHT)
		{
			if (x == destination_x and y == destination_y)
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					std::cout << "Bishops can't jump over pieces" << std::endl;
					return false;
				}
			}
			x--;
			y++;
		}
	}

	else if (destination_x < source_x and destination_y < source_y)
	{


		x = source_x - 1;
		y = source_y - 1;
		while (0 <= x and 0<=y)
		{
			if (x == destination_x and y == destination_y)
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						return false;
					}
					else
					{
						return true;
					}
				}
				else
				{
					return true;
				}
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					std::cout << "Bishops can't jump over pieces" << std::endl;
					return false;
				}
			}
			x--;
			y--;
		}
	}

	std::cout << "This shouldn't happen fix me!" << std::endl;
}


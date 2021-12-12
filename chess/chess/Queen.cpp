#include "Queen.h"

#define BOARD_WIDTH 8
#define BOARD_HEIGHT 8

Queen::Queen(char type, char color) :Piece(type,color)
{

}

Queen::~Queen()
{

}

bool Queen::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	int x, y, i;
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
					std::cout << "Queens can't jump over pieces" << std::endl;
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
		while (x < BOARD_WIDTH and 0 <= y)
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
					std::cout << "Queens can't jump over pieces" << std::endl;
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
		while (0 <= x and y < BOARD_HEIGHT)
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
					std::cout << "Queens can't jump over pieces" << std::endl;
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
		while (0 <= x and 0 <= y)
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
					std::cout << "Queens can't jump over pieces" << std::endl;
					return false;
				}
			}
			x--;
			y--;
		}
	}

	
	else if(source_x == destination_x)
	{
		bool isPlus = source_y < destination_y;
		int difference = abs(source_y - destination_y);
		for (i = 1; i <= difference; i++)
		{
			if (isPlus)
			{
				if (source_y + i == destination_y and source_x == destination_x)
				{
					if (board[source_y + i][source_x] != nullptr)
					{
						if (board[source_y + i][source_x]->getColor() == this->getColor())
						{
							std::cout << "trying to eat your own friends? try again! maybe next time I will allow it" << std::endl;
							return false;
						}
						else
						{
							return true;
						}

					}
					else
					{
						return true;//in this case the square is empty and he can do that
					}
				}
				else
				{
					if (board[source_y + i][source_x] != nullptr)
					{

						return false;

					}
				}

			}
			else
			{
				if (source_y - i == destination_y and source_x == destination_x)
				{
					if (board[source_y - i][source_x] != nullptr)
					{
						if (board[source_y - i][source_x]->getColor() == this->getColor())
						{
							std::cout << "trying to eat your own friends? try again! maybe next time I will allow it" << std::endl;
							return false;
						}
						else
						{
							return true;
						}

					}
					else
					{
						return true;//in this case the square is empty and he can do that
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
	}
	else if (source_y == destination_y)
	{
		bool isPlus = source_x < destination_x;
		int difference = abs(source_x - destination_x);
		for (i = 1; i <= difference; i++)
		{
			if (isPlus)
			{
				if (source_y == destination_y and source_x + i == destination_x)
				{
					if (board[source_y][source_x + i] != nullptr)
					{
						if (board[source_y][source_x + i]->getColor() == this->getColor())
						{
							std::cout << "trying to eat your own friends? try again! maybe next time I will allow it" << std::endl;
							return false;
						}
						else
						{
							return true;
						}

					}
					else
					{
						return true;//in this case the square is empty and he can do that
					}
				}
				else
				{
					if (board[source_y][source_x + i] != nullptr)
					{

						return false;

					}
				}
			}
			else
			{
				if (source_y == destination_y and source_x - i == destination_x)
				{
					if (board[source_y][source_x - i] != nullptr)
					{
						if (board[source_y][source_x - i]->getColor() == this->getColor())
						{
							std::cout << "trying to eat your own friends? try again! maybe next time I will allow it" << std::endl;
							return false;
						}
						else
						{
							return true;
						}

					}
					else
					{
						return true;//in this case the square is empty and he can do that
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
	}


	return false;
}

void Queen::deletePiece()
{
	this->~Queen();
}
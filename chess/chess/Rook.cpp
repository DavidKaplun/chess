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
		for (i = 1; i < difference; i++)
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
	else if(source_y==destination_y)
	{
		bool isPlus = source_x < destination_x;
		int difference = abs(source_x - destination_x);
		for (i = 1; i < difference; i++)
		{
			if (isPlus)
			{
				if (source_y == destination_y and source_x+i == destination_x)
				{
					if (board[source_y][source_x+i] != nullptr)
					{
						if (board[source_y][source_x+i]->getColor() == this->getColor())
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
					if (board[source_y][source_x+i] != nullptr)
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
	else
	{
		return false;
	}
	return true;
}
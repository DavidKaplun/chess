#include "King.h"

#define BOARD_HEIGHT 8
#define BOARD_WIDTH 8

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
	return false;
}

bool King::isInCheckFromRook(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
	int x = 0;
	int y = 0;

	int kingsX = this->getX();
	int kingsY = this->getY();


	for (x = kingsX; x < BOARD_WIDTH; x++)//this for loop checks everything to the right of the king
	{
		if (x != source_x)//we need to address this square as empty because after the move its going to be empty
		{
			if (x == destination_x and kingsY == destination_y)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[kingsY][x] != nullptr)//checks if the square is not empty
				{
					if (board[kingsY][x]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}
					else
					{
						char type = board[kingsY][x]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'r' or type == 'R')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}

		}
	}

	for (x = kingsX; 0<=x; x--)//this for loop checks everything to the left of the king
	{
		if (x != source_x)//we need to address this square as empty because after the move its going to be empty
		{
			if (x == destination_x and kingsY == destination_y)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[kingsY][x] != nullptr)//checks if the square is not empty
				{
					if (board[kingsY][x]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}
					else
					{
						char type = board[kingsY][x]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'r' or type == 'R')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}

		}
	}

	for (y = kingsY; y < BOARD_HEIGHT; y++)//checks every square below the king(remember the index of the squares at the top is lower then at the bottom)
	{
		if (source_y != y)//we need to address this square as empty because after the move its going to be empty
		{
			if (y == destination_y and kingsX == destination_x)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[y][kingsX] != nullptr)//checks if the square is not empty
				{
					if (board[y][kingsX]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}
					else
					{
						char type = board[y][kingsX]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'r' or type == 'R')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}
		}
	}

	for (y = kingsY; 0<=y; y--)//checks every square above the king(remember the index of the squares at the top is lower then at the bottom)
	{
		if (source_y != y)//we need to address this square as empty because after the move its going to be empty
		{
			if (y == destination_y and kingsX == destination_x)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[y][kingsX] != nullptr)//checks if the square is not empty
				{
					if (board[y][kingsX]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}
					else
					{
						char type = board[y][kingsX]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'r' or type == 'R')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}
		}
	}



	return false;
}




int King::getX()
{
	return this->_posX;
}

int King::getY()
{
	return this->_posY;
}
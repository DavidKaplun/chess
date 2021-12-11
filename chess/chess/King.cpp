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
	if (source_x == destination_x and source_y == destination_y)
	{
		std::cout << "This is the same square there is no movement here" << std::endl;
		return false;
	}
	
	if (abs(source_x - destination_x) >= 2 or abs(source_y - destination_y) >= 2)//it should be or 1 or 2 but never bigger or 0(we check if its 0 in the previus if)
	{
		std::cout << "You are trying to move too far my friend" << std::endl;
		return false;
	}

	if (board[destination_y][destination_x]!=nullptr)
	{
		std::cout << "Square you want to move to is not empty"<<std::endl;
		return false;
	}

	int kingsX = destination_x;//it sets the possible positition of the king and checks if in the next position he is under attack
	int kingsY = destination_y;
	
	bool isMovePossible = !(isInDangerAfterMove(-1, -1, -1, -1, kingsX, kingsY, board));//does the reverse because if he is in danger then he can't move
	return isMovePossible;//this should be according to what isInDangerAfterMove function returns
}

bool King::isInDangerAfterMove(int source_x, int source_y, int destination_x, int destination_y,int kingsX,int kingsY, std::vector<std::vector<Piece*>> board)
{
	if (isInCheckFromRook(source_x, source_y, destination_x, destination_y, kingsX, kingsY, board) == true)
	{
		std::cout << "After this move your king will be under check! protect him!" << std::endl;
		return true;
	}

	if (isInCheckFromBishop(source_x, source_y, destination_x, destination_y, kingsX, kingsY, board) == true)
	{
		std::cout << "After this move your king will be under check! protect him!" << std::endl;
		return true;
	}

	if (isInCheckFromKnight(destination_x, destination_y, kingsX, kingsY, board) == true)
	{
		std::cout << "After this move your king will be under check! protect him!" << std::endl;
		return true;
	}

	if (isInCheckFromPawn(destination_x, destination_y, kingsX, kingsY, board) == true)
	{
		std::cout << "After this move your king will be under check! protect him!" << std::endl;
		return true;
	}

	return false;
}

bool King::isInCheckFromPawn(int destination_x, int destination_y,int kingsX,int kingsY, std::vector<std::vector<Piece*>> board)
{
	if (this->getColor() == 'b')
	{
		if (board[kingsY - 1][kingsX - 1] != nullptr)
		{
			if (board[kingsY - 1][kingsX - 1]->getColor() == 'w')
			{
				if (board[kingsY - 1][kingsX - 1]->getType() == 'P')
				{
					return true;//checks if a pawn is to the top left of the black king
				}
			}
		}

		else if (board[kingsY - 1][kingsX + 1] != nullptr)
		{
			if (board[kingsY - 1][kingsX + 1]->getColor() == 'w')
			{
				if (board[kingsY - 1][kingsX + 1]->getType() == 'P')
				{
					return true;//checks if a pawn is to the top right of the black king
				}
			}
		}
	}

	else if (this->getColor() == 'w')
	{
		if (board[kingsY + 1][kingsX - 1] != nullptr)
		{
			if (board[kingsY + 1][kingsX - 1]->getColor() == 'b')
			{
				if (board[kingsY + 1][kingsX - 1]->getType() == 'p')
				{
					return true;//checks if a pawn is to the bottom left of the black king
				}
			}
		}

		else if (board[kingsY + 1][kingsX + 1] != nullptr)
		{
			if (board[kingsY + 1][kingsX + 1]->getColor() == 'b')
			{
				if (board[kingsY + 1][kingsX + 1]->getType() == 'p')
				{
					return true;//checks if a pawn is to the bottom right of the black king
				}
			}
		}
	}
}

bool King::isInCheckFromKnight(int destination_x, int destination_y,int kingsX,int kingsY, std::vector<std::vector<Piece*>> board)
{
	int posChecksX[4] = { kingsX + 1,kingsX - 1,kingsX + 2,kingsX - 2 };
	int posChecksY[4] = { kingsY + 1,kingsY - 1,kingsY + 2,kingsY - 2 };

	int i = 0;
	int curX = 0;
	int curY = 0;

	for (i = 0; i < 4; i++)
	{
		curX = posChecksX[i];
		if (curX >= 0 and curX <= 8)
		{
			if (i > 1)//because we check the first 2 x with the last 2 y and the opposite(a knight can't move 2 squares forward and 2 to the side)
			{
				curY = posChecksY[0];
			}

			else
			{
				curY = posChecksY[2];
			}
			if (curY >= 0 and curY < 8)
			{


				if (board[curY][curX] != nullptr)
				{
					if (board[curY][curX]->getColor() != this->getColor())
					{
						if (destination_y != curY or destination_x != curX)
						{
							char type = board[curY][curX]->getType();
							if (type == 'N' or 'n')
							{
								return true;//yes there is check if the knight is on this square and the requested move doesn't cover this square
							}
						}
					}
				}
			}

			if (i > 1)//because we check the first 2 x with the last 2 y and the opposite(a knight can't move 2 squares forward and 2 to the side)
			{
				curY = posChecksY[1];
			}

			else
			{
				curY = posChecksY[3];
			}
			if (curY >= 0 and curY < 8)
			{
				if (board[curY][curX] != nullptr)
				{
					if (board[curY][curX]->getColor() != this->getColor())
					{
						if (destination_y != curY or destination_x != curX)
						{
							char type = board[curY][curX]->getType();
							if (type == 'N' or 'n')
							{
								return true;//yes there is check if the knight is on this square and the requested move doesn't cover this square
							}
						}
					}
				}
			}
			
		}
	}
	

	return false;
}



bool King::isInCheckFromBishop(int source_x, int source_y, int destination_x, int destination_y,int kingsX,int kingsY, std::vector<std::vector<Piece*>> board)
{
	

	int x = kingsX;
	int y = kingsY;
	while (x < BOARD_WIDTH and y < BOARD_HEIGHT)//checks everything to the right bottom of the king
	{
		x++;
		y++;
		if (x != source_x and y != source_y)
		{
			if (x == destination_x and y == destination_y)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}

					else
					{
						char type = board[y][x]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'b' or type == 'B')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}
		}
	}
	
	x = kingsX;
	y = kingsY;

	while (x < BOARD_WIDTH and 0<=y)//checks everything to the right top of the king
	{
		x++;
		y--;
		if (x != source_x and y != source_y)
		{
			if (x == destination_x and y == destination_y)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}

					else
					{
						char type = board[y][x]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'b' or type == 'B')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}
		}
	}

	x = kingsX;
	y = kingsY;

	while (0<=x and 0 <=y)//checks everything to the left top of the king
	{
		x--;
		y--;
		if (x != source_x and y != source_y)
		{
			if (x == destination_x and y == destination_y)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}

					else
					{
						char type = board[y][x]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'b' or type == 'B')
						{
							return true;//if the piece on this square is a queen or a rook then its a check
						}
					}
				}
			}
		}
	}

	x = kingsX;
	y = kingsY;

	while (0 <= x and y<BOARD_HEIGHT)//checks everything to the left bottom of the king
	{
		x--;
		y++;
		if (x != source_x and y != source_y)
		{
			if (x == destination_x and y == destination_y)
			{
				break;//breaks the loop because the piece blocks the king from check in this direction
			}
			else
			{
				if (board[y][x] != nullptr)
				{
					if (board[y][x]->getColor() == this->getColor())
					{
						break;//because the piece thats on the square is the same color and it covers the check
					}

					else
					{
						char type = board[y][x]->getType();//just to make the if statement shorter
						if (type == 'Q' or type == 'q' or type == 'b' or type == 'B')
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

bool King::isInCheckFromRook(int source_x, int source_y, int destination_x, int destination_y,int kingsX,int kingsY, std::vector<std::vector<Piece*>> board)
{
	int x = 0;
	int y = 0;


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
#include "Knight.h"

Knight::Knight(char type, char color):Piece(type,color)
{
	
}

Knight::~Knight()
{

}

bool Knight::isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board)
{
    int posX[4] = { source_x - 1, source_x + 1, source_x - 2, source_x + 2 };
    int posY[4] = { source_y - 1, source_y + 1, source_y - 2, source_y + 2 };

    int x, y;
    /*
    arrow code spotted
    i think i would flattten it by separately checking the destinations and if they make sense go to the 'if's
    in addition, i would have joined the 2 most outed 'if's together with an 'and' logic gate
    i would have written the following code:
    */

    /*
    bool isPos = false;
    for (int i = 0; i < 4; i++)
    {
        if (destination_x == posX[i])
        {
            isPos = true;
            break;
        }
    }
    //check the 'isPos' and reset it
    for (int i = 0; i < 4; i++)
    {
        if (destination_y == posY[i])
        {
            isPos = true;
            break;
        }
    }
    //check the 'isPos'
    if (board[destination_y][destination_x] == nullptr || 
        board[destination_y][destination_x]->getColor() != this->getColor())
    {
        return true;
    }
    else
    {
        std::cout << "trying to eat your friends? not cool bro" << std::endl;
        return false;
    }
    */
    for (x = 0; x < 4; x++)
    {
        if (destination_x == posX[x])
        {
            if (x < 2)
            {
                for (y = 2; y < 4; y++)
                {
                    if (destination_y == posY[y])
                    {
                        if (board[destination_y][destination_x] != nullptr)
                        {
                            if (board[destination_y][destination_x]->getColor() == this->getColor())
                            {
                                std::cout << "trying to eat your friends? not cool bro" << std::endl;
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
                }

            }
            else if (x > 2)
            {
                for (y = 0; y < 2; y++)
                {
                    if (destination_y == posY[y])
                    {
                        if (board[destination_y][destination_x] != nullptr)
                        {
                            if (board[destination_y][destination_x]->getColor() == this->getColor())
                            {
                                std::cout << "trying to eat your friends? not cool" << std::endl;
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
                }
            }
        }
    }
    return false;
}

void Knight::deletePiece()
{
	this->~Knight();
}



#include "Menu.h"
#include "Pipe.h"
#include <iostream>
#include <thread>

using std::cout;
using std::endl;
using std::string;

bool check_move(std::string move);
void main()
{
	Menu* menu = new Menu();
	bool run = true;
	King* cur_king;
	std::string move;
	bool isLegalMove = false;
	char turn;
	int sourceX, sourceY, destinationX, destinationY;
	while (run)
	{
		printBoard(menu->getBoard());
		if (menu->getNumOfMoves() % 2 == 0)
		{
			std::cout << "Turn white" << std::endl;
			turn = 'w';
		}
		else
		{
			std::cout << "Turn black" << std::endl;
			turn = 'b';
		}
		while (isLegalMove == false)
		{
			std::cout << "Enter Your move(example:e2e4):" << std::endl;
			std::cin >> move;
			isLegalMove = check_move(move);
			if (isLegalMove)
			{
				sourceX = int(move[0]) - 97;
				sourceY = 7-(int(move[1]) - 49);
				destinationX = int(move[2]) - 97;
				destinationY = 7-(int(move[3]) - 49);
				if (menu->getBoard()[sourceY][sourceX] != nullptr)
				{
					if (menu->getBoard()[sourceY][sourceX]->getColor() == turn)
					{


						if (turn == 'w')//for white
						{
							//for the king
							if (menu->getBoard()[sourceY][sourceX]->getType() == 'K')
							{
								cur_king = menu->getWhiteKing();
								isLegalMove= cur_king->isMovePossible(sourceX, sourceY, destinationX, destinationY, menu->getBoard());
								if (isLegalMove)
								{
									isLegalMove = !(cur_king->isInCheckFromKing(menu->getBlackKing()->getX(), menu->getBlackKing()->getY(),destinationX,destinationY));
									if (isLegalMove)
									{
										menu->getWhiteKing()->setX(destinationX);
										menu->getWhiteKing()->setY(destinationY);
									}
									
								}
							}

							//for the rest of the pieces
							else
							{
								cur_king = menu->getWhiteKing();
								isLegalMove = !(cur_king->isInDangerAfterMove(sourceX, sourceY, destinationX, destinationY, cur_king->getX(), cur_king->getY(), menu->getBoard())); //!
								if (isLegalMove)
								{
									isLegalMove = menu->getBoard()[sourceY][sourceX]->isMovePossible(sourceX, sourceY, destinationX, destinationY, menu->getBoard());
								}
								
							}
						}


						else//for black
						{
							//for the king
							if (menu->getBoard()[sourceY][sourceX]->getType() == 'k')
							{
								if (isLegalMove)
								{
									cur_king = menu->getBlackKing();
									isLegalMove = cur_king->isMovePossible(sourceX, sourceY, destinationX, destinationY, menu->getBoard());
									if (isLegalMove)
									{
										isLegalMove = !(cur_king->isInCheckFromKing(menu->getWhiteKing()->getX(), menu->getWhiteKing()->getY(),destinationX,destinationY));
										if (isLegalMove)
										{
											menu->getBlackKing()->setX(destinationX);
											menu->getBlackKing()->setY(destinationY);
										}
										
									}
								}
								
							}

							//for the rest of the pieces
							else
							{
								cur_king = menu->getBlackKing();
								isLegalMove = !(cur_king->isInDangerAfterMove(sourceX, sourceY, destinationX, destinationY, cur_king->getX(), cur_king->getY(), menu->getBoard()));
								if (isLegalMove)
								{
									isLegalMove = menu->getBoard()[sourceY][sourceX]->isMovePossible(sourceX, sourceY, destinationX, destinationY, menu->getBoard());
								}
								
							}
						}
					}
					else
					{
						isLegalMove = false;
						std::cout << "Error you can't move your opponents pieces!" << std::endl;
					}
				}
				else
				{
					std::cout << "Error: you cant move from an empty square" << std::endl;
					isLegalMove = false;
				}
			}
			else
			{
				std::cout << "You are trying to move out of the board. You can't do that!" << std::endl;
			}

		}

		menu->updateBoard(move);
		isLegalMove = false;
		menu->incNumOfMoves();

	}
}


bool check_move(std::string move)
{
	if (move.length()!=4)
	{
		return false;
	}
	if (move[0] < 'a' or move[0]>'h')
	{
		return false;
	}
	if (move[2] < 'a' or move[2]>'h')
	{
		return false;
	}

	if (move[1] < '1' or move[1]>'8')
	{
		return false;
	}
	if (move[3] < '1' or move[3]>'8')
	{
		return false;
	}
	if (move[0] == move[2] and move[1] == move[3])
	{
		return false;
	}
	return true;
}

























/*
This file servers as an example of how to use Pipe.h file.
It is recommended to use the following code in your project,
in order to read and write information from and to the Backend
*/






void main1()
{
	srand(time_t(NULL));

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "cant connect to graphics" << endl;
		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "trying connect again.." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else 
		{
			p.close();
			return;
		}
	}

	char msgToGraphics[1024];
	// msgToGraphics should contain the board string accord the protocol
	// YOUR CODE

	strcpy_s(msgToGraphics, "rnbkqbnLpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
	
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		// should handle the string the sent from graphics
		// according the protocol. Ex: e2e4           (move e2 to e4)
		
		// YOUR CODE
		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation

		/******* JUST FOR EREZ DEBUGGING ******/
		int r = rand() % 10; // just for debugging......
		msgToGraphics[0] = (char)(1 + '0');
		msgToGraphics[1] = 0;
		/******* JUST FOR EREZ DEBUGGING ******/


		// return result to graphics		
		p.sendMessageToGraphics(msgToGraphics);   

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
		std::cout << msgFromGraphics << std::endl;
	}

	p.close();
}
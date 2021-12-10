
#include "Menu.h"

bool check_move(std::string move);
int main()
{
	Menu* menu = new Menu();
	printBoard(menu->getBoard());
	std::string move;
	bool isLegalMove = false;
	while (isLegalMove == false)
	{
		std::cout << "Enter Your move(example:e2e4):" << std::endl;
		std::cin >> move;
		isLegalMove = check_move(move);
	}
	
	menu->incNumOfMoves();
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

//#include "Pipe.h"
//#include <iostream>
//#include <thread>
//
//using std::cout;
//using std::endl;
//using std::string;
//
//
//void main()
//{
//	srand(time_t(NULL));
//
//	
//	Pipe p;
//	bool isConnect = p.connect();
//	
//	string ans;
//	while (!isConnect)
//	{
//		cout << "cant connect to graphics" << endl;
//		cout << "Do you try to connect again or exit? (0-try again, 1-exit)" << endl;
//		std::cin >> ans;
//
//		if (ans == "0")
//		{
//			cout << "trying connect again.." << endl;
//			Sleep(5000);
//			isConnect = p.connect();
//		}
//		else 
//		{
//			p.close();
//			return;
//		}
//	}
//	
//
//	char msgToGraphics[1024];
//	// msgToGraphics should contain the board string accord the protocol
//	// YOUR CODE
//
//	strcpy_s(msgToGraphics, "rnbkqbnrpppppppp################################PPPPPPPPRNBKQBNR1"); // just example...
//	
//	p.sendMessageToGraphics(msgToGraphics);   // send the board string
//
//	// get message from graphics
//	string msgFromGraphics = p.getMessageFromGraphics();
//
//	while (msgFromGraphics != "quit")
//	{
//		// should handle the string the sent from graphics
//		// according the protocol. Ex: e2e4           (move e2 to e4)
//		
//		// YOUR CODE
//		strcpy_s(msgToGraphics, "YOUR CODE"); // msgToGraphics should contain the result of the operation
//
//		/******* JUST FOR EREZ DEBUGGING ******/
//		int r = rand() % 10; // just for debugging......
//		msgToGraphics[0] = (char)(1 + '0');
//		msgToGraphics[1] = 0;
//		/******* JUST FOR EREZ DEBUGGING ******/
//
//
//		// return result to graphics		
//		p.sendMessageToGraphics(msgToGraphics);   
//
//		// get message from graphics
//		msgFromGraphics = p.getMessageFromGraphics();
//	}
//
//	p.close();
//}
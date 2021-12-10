#pragma once
#include "Piece.h"
class Menu
{
private:
	std::vector<std::vector<Piece*>> _board;
	int _numOfMoves;
public:
	Menu();
	void incNumOfMoves();
	~Menu();
};
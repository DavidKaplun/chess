#pragma once
#include "piece.h"
#include <iostream>

class Rook : public Piece
{
private:
	bool _isFirstMove;
public:
	Rook(char type, char color);
	~Rook();

};
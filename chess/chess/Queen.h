#pragma once
#include "Piece.h"

class Queen :public Piece
{

public:
	Queen(char x, char y, char type, char color);
	~Queen();
};
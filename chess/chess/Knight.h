#pragma once
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(char x, char y, char type, char color);
	~Knight();
};
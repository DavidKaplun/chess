#pragma once
#include "Piece.h"

class King :public Piece
{
public:
	King(char x, char y, char type, char color);
	~King();
};
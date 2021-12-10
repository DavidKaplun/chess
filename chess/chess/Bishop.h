#pragma once
#include "Piece.h"

class Bishop :public Piece
{
public:
	Bishop(char x, char y, char type, char color);
	~Bishop();
};
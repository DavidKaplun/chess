#pragma once
#include "Piece.h"

class Pawn :public Piece
{
private:
	bool _isFirstMove;

public:
	Pawn(char type, char color);
	~Pawn();
};
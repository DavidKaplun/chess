#pragma once
#include "Piece.h"

class Pawn :public Piece
{
private:
	bool _isFirstMove;

public:
	Pawn(char type, char color);
	~Pawn();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y) override;
};
#pragma once
#include "Piece.h"

class Queen :public Piece
{

public:
	Queen(char type, char color);
	~Queen();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y) override;
};
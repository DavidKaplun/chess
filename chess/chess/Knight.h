#pragma once
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(char type, char color);
	~Knight();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board) override;
};
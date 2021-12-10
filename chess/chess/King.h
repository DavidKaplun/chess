#pragma once
#include "Piece.h"

class King :public Piece
{
public:
	King(char type, char color);
	~King();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board) override;
};
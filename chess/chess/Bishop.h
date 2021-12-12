#pragma once
#include "Piece.h"

class Bishop :public Piece
{
public:
	Bishop(char type, char color);
	~Bishop();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board) override;
	virtual void deletePiece() override;
};
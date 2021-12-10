#pragma once
#include "Piece.h"

class Bishop :public Piece
{
public:
	Bishop(char x, char y, char type, char color);
	~Bishop();
	virtual void change_pos_moves(std::vector<std::vector<Piece*>> board) override;
};
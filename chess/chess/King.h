#pragma once
#include "Piece.h"

class King :public Piece
{
public:
	King(char x, char y, char type, char color);
	~King();
	virtual void change_pos_moves(std::vector<std::vector<Piece*>> board) override;
};
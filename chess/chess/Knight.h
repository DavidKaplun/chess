#pragma once
#include "Piece.h"

class Knight :public Piece
{
public:
	Knight(char x, char y, char type, char color);
	~Knight();
	virtual void change_pos_moves(std::vector<std::vector<Piece*>> board) override;
};
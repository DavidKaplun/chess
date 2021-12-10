#pragma once
#include "Piece.h"

class Queen :public Piece
{

public:
	Queen(char x, char y, char type, char color);
	~Queen();
	virtual void change_pos_moves(std::vector<std::vector<Piece*>> board) override;
};
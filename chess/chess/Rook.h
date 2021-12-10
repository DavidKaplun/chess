#pragma once
#include "piece.h"
#include <iostream>

class Rook : public Piece
{

public:
	Rook(char y, char x, char type, char color);
	~Rook();
	virtual void change_pos_moves(std::vector<std::vector<Piece*>> board) override;

};
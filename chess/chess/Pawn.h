#pragma once
#include "Piece.h"

class Pawn :public Piece
{
private:
	bool isFirstMove;

public:
	Pawn(char x, char y, char type, char color);
	~Pawn();
	virtual void change_pos_moves(std::vector<std::vector<Piece*>> board) override;
};
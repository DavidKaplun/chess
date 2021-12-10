#pragma once
#include "piece.h"
#include <iostream>

class Rook : public Piece
{
private:
	bool _isFirstMove;
public:
	Rook(char type, char color);
	~Rook();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board) override;

};
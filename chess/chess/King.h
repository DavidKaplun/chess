#pragma once
#include "Piece.h"

class King :public Piece
{
private:
	int _posX;
	int _poxY;
public:
	King(char type, char color);
	~King();
	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board) override;
	bool isInDangerAfterMove(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board);
	bool isInCheckFromRook(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board);
};
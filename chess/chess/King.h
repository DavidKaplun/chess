#pragma once
#include "Piece.h"

class King :public Piece
{
private:
	int _posX;
	int _posY;
public:
	King(char type, char color);
	~King();

	virtual bool isMovePossible(int source_x, int source_y, int destination_x, int destination_y, std::vector<std::vector<Piece*>> board) override;
	virtual void deletePiece() override;

	bool isInDangerAfterMove(int source_x, int source_y, int destination_x, int destination_y,int kingsX,int kingsY, std::vector<std::vector<Piece*>> board);
	bool isInCheckFromRook(int source_x, int source_y, int destination_x, int destination_y, int kingsX, int kingsY, std::vector<std::vector<Piece*>> board);
	bool isInCheckFromBishop(int source_x, int source_y, int destination_x, int destination_y, int kingsX, int kingsY, std::vector<std::vector<Piece*>> board);
	bool isInCheckFromKnight(int destination_x, int destination_y, int kingsX, int kingsY, std::vector<std::vector<Piece*>> board);
	bool isInCheckFromPawn(int destination_x, int destination_y, int kingsX, int kingsY, std::vector<std::vector<Piece*>> board);

	//Getters
	int getY();
	int getX();

	//Setters
	void setX(int x);
	void setY(int y);
};
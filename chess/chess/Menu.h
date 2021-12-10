#pragma once
#include "Piece.h"
void createBoard(std::vector<std::vector<Piece*>>& board);
void addPiecesToBoard(std::vector<std::vector<Piece*>>& board);
void printBoard(std::vector<std::vector<Piece*>>& board);

class Menu
{
private:
	std::vector<std::vector<Piece*>> _board;
	int _numOfMoves;
public:
	Menu();
	void incNumOfMoves();
	std::vector<std::vector<Piece*>>& getBoard();
	~Menu();
};
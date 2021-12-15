#pragma once
#include "Piece.h"
#include "King.h"

void addPiecesToBoard();
void printBoard(std::vector<std::vector<Piece*>>& board);

class Menu
{
private:
	std::vector<std::vector<Piece*>> _board;
	int _numOfMoves;
	bool isKingInDanger;
	King* _whiteKing;
	King* _blackKing;
public:
	Menu();
	void incNumOfMoves();
	std::vector<std::vector<Piece*>>& getBoard();
	void updateBoard(std::string move);
	void addPiecesToBoard();
	void createBoard();
	int getNumOfMoves();
	King* getWhiteKing();
	King* getBlackKing();

	~Menu();
};
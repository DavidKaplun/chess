#pragma once
#include <iostream>
#include <vector>

class Piece
{
protected:	
	char _posX; // the letters
	char _posY; // the values
	std::vector<std::string> _posMoves;
	char _color;
	char _type;

public:
	Piece(char x,char y,char type,char color);
	~Piece();
	virtual void move(char x, char y);
};


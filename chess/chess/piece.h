#pragma once
#include <iostream>
#include <vector>

class Piece
{
protected:	
	char _color;
	char _type;

public:
	Piece(char type,char color);
	~Piece();

	char getType();
	char getColor();
};


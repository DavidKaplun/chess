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
	virtual bool isMovePossible(int source_x,int source_y,int destination_x,int destination_y)=0;
	char getType();
	char getColor();
};


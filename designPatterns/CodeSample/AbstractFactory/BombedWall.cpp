#include "BombedWall.h"
#include "global.h"

//---- BombedWall ---------------------------------------------------------

BombedWall::BombedWall(bool hasBomb) : Wall()
{
	this->_bomb = hasBomb;
}

BombedWall::~BombedWall() { }

void BombedWall::Print(int indent) {
	PrintIndent(indent);
	printf("BombedWall:\n");
	
	PrintIndent(indent+2);
	if(this->_bomb) printf("_bomb = true\n");
	else printf("_bomb = false\n");

	Wall::Print(indent+2);
}

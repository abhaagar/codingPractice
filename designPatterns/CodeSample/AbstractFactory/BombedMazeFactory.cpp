#include "BombedMazeFactory.h"
#include "BombedWall.h"

//---- BombedMazeFactory ---------------------------------------------------------

BombedMazeFactory::BombedMazeFactory() : MazeFactory() { }

BombedMazeFactory::~BombedMazeFactory() { }

class Wall * BombedMazeFactory::MakeWall() const {
	return new BombedWall();
}

void BombedMazeFactory::Print(int indent) {
	PrintIndent(indent);
	printf("BombedMazeFactory\n");
		
	MazeFactory::Print(indent+2);
}

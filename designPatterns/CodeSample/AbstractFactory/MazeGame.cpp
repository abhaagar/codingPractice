#include "MazeGame.h"
#include "MazeFactory.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

//---- MazeGame ---------------------------------------------------------

MazeGame::MazeGame() : Object() { }

MazeGame::~MazeGame() { }

class Maze * MazeGame::CreateMaze(class MazeFactory * factory) {
	Maze * aMaze; aMaze = factory->MakeMaze();
	Room * r1; r1 = factory->MakeRoom(1);
	Room * r2; r2 = factory->MakeRoom(2);
	Door * theDoor; theDoor = factory->MakeDoor(r1,r2);
	
	aMaze->AddRoom(r1);
	aMaze->AddRoom(r2);
	
	r1->SetSide(North, factory->MakeWall());
	r1->SetSide(East, theDoor);
	r1->SetSide(South, factory->MakeWall());
	r1->SetSide(West, factory->MakeWall());
	
	r2->SetSide(North, factory->MakeWall());
	r2->SetSide(East, factory->MakeWall());
	r2->SetSide(South, factory->MakeWall());
	r2->SetSide(West, theDoor);
	
	return aMaze;
}

void MazeGame::Print(int indent) {
	PrintIndent(indent);
	printf("MazeGame\n");
	
	Object::Print(indent+2);
}

#include "MazeFactory.h"
#include "Maze.h"
#include "Wall.h"
#include "Room.h"
#include "Door.h"

//---- MazeFactory ---------------------------------------------------------

MazeFactory::MazeFactory() : Object() { }

MazeFactory::~MazeFactory() { }

class Maze * MazeFactory::MakeMaze() const {
	return new Maze();
}

class Wall * MazeFactory::MakeWall() const {
	return new Wall();
}

class Room * MazeFactory::MakeRoom(int n) const {
	return new Room(n);
}

class Door * MazeFactory::MakeDoor(class Room * r1, class Room * r2) const {
	return new Door(r1, r2);
}

void MazeFactory::Print(int indent) {
	PrintIndent(indent);
	printf("MazeFactory\n");
		
	Object::Print(indent+2);
}

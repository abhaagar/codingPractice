#include "MazeGame.h"
#include "Builder.h"
#include "Maze.h"
#include "Room.h"
#include "Door.h"
#include "Wall.h"

//---- MazeGame ---------------------------------------------------------

MazeGame::MazeGame() : Object() { }

MazeGame::~MazeGame() { }

Maze* MazeGame::CreateMaze (MazeBuilder& builder) {
    builder.BuildMaze();

    builder.BuildRoom(1);
    builder.BuildRoom(2);
    builder.BuildDoor(1, 2);

    return builder.GetMaze();
}
/*
*/
Maze* MazeGame::CreateComplexMaze (MazeBuilder& builder) {
    builder.BuildRoom(1);
    // ...
    builder.BuildRoom(1001);

    return builder.GetMaze();
}
/*
*/

void MazeGame::Print(int indent) {
	PrintIndent(indent);
	printf("MazeGame\n");
	
	Object::Print(indent+2);
}

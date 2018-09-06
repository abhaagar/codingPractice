//-*-Mode: C++;-*-
#ifndef _MazeGame_h_
#define _MazeGame_h_

#include "Object.h"

//---- MazeGame -----------------------------------------------------------

// Vorwaertsdeklaration
class Maze;
class MazeBuilder;

class MazeGame : public Object
{
public:
	MazeGame();
	virtual ~MazeGame();
	
	Maze* MazeGame::CreateMaze (MazeBuilder& builder);
    Maze* MazeGame::CreateComplexMaze (MazeBuilder& builder);
	
	virtual void Print(int indent = 0);
};

#endif

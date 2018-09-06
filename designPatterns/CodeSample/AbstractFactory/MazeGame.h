//-*-Mode: C++;-*-
#ifndef _MazeGame_h_
#define _MazeGame_h_

#include "Object.h"

//---- MazeGame -----------------------------------------------------------

// Vorwaertsdeklaration
class Maze;
class MazeFactory;

class MazeGame : public Object
{
public:
	MazeGame();
	virtual ~MazeGame();
	
	class Maze * CreateMaze(class MazeFactory *factory);
	
	virtual void Print(int indent = 0);
};

#endif

//-*-Mode: C++;-*-
#ifndef _MazeFactory_h_
#define _MazeFactory_h_

#include "Object.h"

//---- MazeFactory -----------------------------------------------------------

// Vorwaertsdeklarationen
class Maze;
class Wall;
class Room;
class Door;

class MazeFactory : public Object
{
public:
	MazeFactory();
	virtual ~MazeFactory();

	virtual class Maze * MakeMaze() const;
	virtual class Wall * MakeWall() const;
	virtual class Room * MakeRoom(int n) const;
	virtual class Door * MakeDoor(class Room * r1, class Room * r2) const;
		
	virtual void Print(int indent = 0);
};

//ik added:
class MazeFactory * FactoryInstance();
class MazeFactory * FactoryInstance( bool bombed_ );

#endif

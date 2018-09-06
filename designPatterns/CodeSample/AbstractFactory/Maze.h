//-*-Mode: C++;-*-
#ifndef _Maze_h_
#define _Maze_h_

#include "MapSite.h"

//---- Maze -----------------------------------------------------------

// Vorwaertsdeklaration
class ObjectArray;

class Maze : public Object
{
public:
	Maze();
	virtual ~Maze();

	void AddRoom(class Room *);	
	class Room * RoomNo(int) const;
	
	virtual void Print(int indent = 0);

private:
	class ObjectArray *Rooms;
};

#endif

//-*-Mode: C++;-*-
#ifndef _Room_h_
#define _Room_h_

#include "MapSite.h"
#include "global.h"

//---- Room -----------------------------------------------------------

// Vorwaertsdeklaration
class ObjectArray;

class Room : public MapSite
{
public:
	Room(int roomNo);
	virtual ~Room();
	
	class MapSite* GetSide(Direction) const;
	int GetRoomNo() const;
	
	void SetSide(Direction, class MapSite *);
	
	virtual void Enter();
	
	virtual void Print(int indent = 0);

private:
	class ObjectArray *_sides;
	int _roomNumber;
};

#endif

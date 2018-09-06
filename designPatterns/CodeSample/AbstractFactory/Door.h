//-*-Mode: C++;-*-
#ifndef _Door_h_
#define _Door_h_

#include "MapSite.h"

//---- Door -----------------------------------------------------------

// Vorwaertsdeklaration
class Room;

class Door : public MapSite
{
public:
	Door(class Room * = 0, class Room * = 0);
	virtual ~Door();
	
	virtual void Enter();
	class Room * OtherSideFrom(class Room *);
	
	virtual void Print(int indent = 0);

private:
	class Room * _room1;
	class Room * _room2;
	bool _isOpen;
};

#endif

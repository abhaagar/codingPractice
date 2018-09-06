//-*-Mode: C++;-*-
#ifndef _BombedWall_h_
#define _BombedWall_h_

#include "Wall.h"

//---- BombedWall -----------------------------------------------------------

class BombedWall : public Wall
{
public:
	BombedWall(bool hasHomb = false);
	virtual ~BombedWall();

	bool HasBomb();
	
	virtual void Print(int indent = 0);
private:
	bool _bomb;
};

#endif

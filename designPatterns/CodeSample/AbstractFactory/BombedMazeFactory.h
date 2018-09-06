//-*-Mode: C++;-*-
#ifndef _BombedMazeFactory_h_
#define _BombedMazeFactory_h_

#include "MazeFactory.h"

//---- BombedMazeFactory -----------------------------------------------------------

class BombedMazeFactory : public MazeFactory
{
public:
	BombedMazeFactory();
	virtual ~BombedMazeFactory();

	virtual class Wall * MakeWall() const;
		
	virtual void Print(int indent = 0);
};

#endif

//-*-Mode: C++;-*-
#ifndef _Wall_h_
#define _Wall_h_

#include "MapSite.h"

//---- Wall -----------------------------------------------------------

class Wall : public MapSite
{
public:
	Wall();
	virtual ~Wall();
	
	virtual void Enter();

	virtual void Print(int indent = 0);
};

#endif

//-*-Mode: C++;-*-
#ifndef _MapSite_h_
#define _MapSite_h_

#include "Object.h"

//---- MapSite -----------------------------------------------------------

class MapSite : public Object
{
public:
    virtual void Enter() = 0;
    
    virtual void Print(int indent = 0);
    
protected:
	MapSite();
	virtual ~MapSite();
};

#endif

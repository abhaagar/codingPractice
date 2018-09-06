#ifndef _ObjectArray_h
#define _ObjectArray_h

#include "Object.h"

class ObjectArray : public Object {

public:

	ObjectArray();
	virtual ~ObjectArray();

	void FreeArray();

	virtual class Object *GetAt(int pAt);
	virtual class Object *PutAt(int pAt, class Object *pO, bool replace = true);

	bool IsEmpty ();
	virtual void Print(int indent = 0);
	
private:
	class ObjectLink *_first;
};

#endif

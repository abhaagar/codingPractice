#ifndef _ObjectLink_h
#define _ObjectLink_h

#include "Object.h"

class ObjectLink : public Object {

public:
	ObjectLink (int index, class Object *pOn);
	virtual ~ObjectLink ();

	class Object *GetValue();
	void SetValue(class Object *);
	int GetIndex();

	void SetNext(class ObjectLink *pO);
	class ObjectLink *GetNext();

	virtual void Print(int indent = 0);

private:
	class ObjectLink *_previous;
	class ObjectLink *_next;
	class Object *_value;
	int _index;
};

#endif

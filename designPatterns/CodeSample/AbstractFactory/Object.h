#ifndef _pa_test_OBJECT_FIRST
#define _pa_test_OBJECT_FIRST

#include "global.h"

class Object {
public:
    Object (int pId = 0);
    virtual ~Object ();

    virtual void Print (int indent = 0);
private:
    int Id;
};

#endif

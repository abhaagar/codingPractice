#include "ObjectLink.h"

ObjectLink::ObjectLink (int index, class Object *pO)
: Object(), _previous(0), _next(0) /* , Value(pO) */ { 
    _value = pO;
    _index = index;
}

ObjectLink::~ObjectLink () { }

void ObjectLink::SetNext (class ObjectLink *oL) {
    this->_next = oL;
    if(oL) {
        oL->_previous = this;
    }
}

class ObjectLink *ObjectLink::GetNext () {
    return this->_next;
}

class Object *ObjectLink::GetValue () {
    return this->_value;
}

void ObjectLink::SetValue(class Object *o) {
    this->_value = o;
}

int ObjectLink::GetIndex() {
    return this->_index;
}

void ObjectLink::Print(int indent) {
    PrintIndent(indent);
    printf("ObjectLink:\n");

    PrintIndent(indent+2);
    printf("_index = %d\n",this->_index);

    PrintIndent(indent+2);
    printf("_previous = %p\n", this->_previous);

    PrintIndent(indent+2);
    printf("_next = %p\n", this->_next);

    PrintIndent(indent+2);
    if(this->_value) {
        printf("_value:\n");
        this->_value->Print(indent+2);
    } else {
        printf("_value = NULL");
    }

    Object::Print(indent+2);
}


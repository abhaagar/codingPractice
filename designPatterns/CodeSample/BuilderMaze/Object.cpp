#include "Object.h"

Object::Object (int pId) {
    this->Id= pId;
}

Object::~Object () {
}

void Object::Print (int indent) {
    PrintIndent(indent);
    printf("Object:\n");

    PrintIndent(indent+2);
    printf("Id = %d\n",this->Id);
}


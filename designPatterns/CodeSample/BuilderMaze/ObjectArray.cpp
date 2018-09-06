#include "ObjectArray.h"

#include "Object.h"
#include "ObjectLink.h"

#include <stdio.h>

ObjectArray::ObjectArray () : Object()
{
	this->_first = 0;
}

ObjectArray::~ObjectArray() {
	ObjectLink *help = 0;
	
	while(this->_first != NULL) {
		help = this->_first->GetNext();
		delete this->_first;
		this->_first = help;
	}
	this->_first = 0;
}

void ObjectArray::FreeArray() {
	ObjectLink *help; help = this->_first;
	Object *object = 0;
	
	while(this->_first != NULL) {
		help = this->_first->GetNext();
		object = this->_first->GetValue();
		delete object;
		delete this->_first;
		this->_first = help;
	}
	this->_first = 0;
}

class Object *ObjectArray::GetAt(int pAt) {
	ObjectLink *link;
	link= this->_first;
	while(link && (link->GetIndex() < pAt)) {
		link = link->GetNext();
	}
	if(link && (pAt == link->GetIndex())) {
		return link->GetValue();
	} else {
		return 0;
	}
}

class Object * ObjectArray::PutAt (int pAt, class Object *pO, bool replace) {
	ObjectLink *prevLink;
	ObjectLink *curLink;
	prevLink = 0;
	curLink = this->_first;
	while(curLink && (curLink->GetIndex() < pAt)) {
		prevLink = curLink;
		curLink = curLink->GetNext();
	}
	if(curLink && (pAt == curLink->GetIndex())) {
		if(replace) {
			Object *o; o = curLink->GetValue();
			curLink->SetValue(pO);
			return o;
		} else {
			return 0;
		}
	} else {
		ObjectLink *newLink = new ObjectLink(pAt,pO);
		newLink->SetNext(curLink);
		if(this->_first == curLink) {
			this->_first = newLink;
		}
		if(prevLink) {
			prevLink->SetNext(newLink);
		}				
		return 0;
	}
}

bool ObjectArray::IsEmpty () {
	return (this->_first == 0);
}

void ObjectArray::Print(int indent) {
	ObjectLink *curLink;

	PrintIndent(indent);
	printf("ObjectArray:\n");
	
	if(this->IsEmpty()) {
		PrintIndent(indent+2);
		printf("I contain no objects\n");
	} else {
		PrintIndent(indent+2);
		printf("I contain following objects:\n");
		
		curLink = this->_first;
		while (curLink) {
			curLink->GetValue()->Print(indent+2);
			curLink = curLink->GetNext();
		}
	}
	
	Object::Print(indent+2);
}

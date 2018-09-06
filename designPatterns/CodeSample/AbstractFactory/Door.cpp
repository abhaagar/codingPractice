#include "Door.h"
#include "Room.h"

//---- Door ---------------------------------------------------------

Door::Door(class Room * room1, class Room * room2) : MapSite()
{
	this->_room1 = room1;
	this->_room2 = room2;
}

Door::~Door() { }

void Door::Enter() {
	if(this->_isOpen) {
		/* Um Code erweitern, falls Maze fuer Spiel verwendet wird */
	}
}

class Room * Door::OtherSideFrom(class Room *room) {
	if(room == this->_room1) {
		return this->_room2;
	} else if(room == this->_room2) {
		return this->_room1;
	} else {
		return 0;
	}
}

void Door::Print(int indent) {
	PrintIndent(indent);
	printf("Door:\n");
	
	PrintIndent(indent+2);
	if(this->_room1) printf("_room1 = %d\n", this->_room1->GetRoomNo());
	else printf("_room1 = NULL\n");
	
	PrintIndent(indent+2);
	if(this->_room2) printf("_room2 = %d\n", this->_room2->GetRoomNo());
	else printf("_room2 = NULL\n");
	
	PrintIndent(indent+2);
	if(this->_isOpen) printf("_isOpen = true\n");
	else printf("_isOpen = false\n");
	
	MapSite::Print(indent+2);
}

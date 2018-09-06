#include "Room.h"
#include "ObjectArray.h"

//---- Room ---------------------------------------------------------

Room::Room(int roomNo) : MapSite()
{
	this->_roomNumber = roomNo;
	this->_sides = new ObjectArray();
}

Room::~Room()
{
	delete this->_sides;
}

class MapSite* Room::GetSide(Direction d) const {
	return (MapSite *) this->_sides->GetAt(d);
}

int Room::GetRoomNo() const {
	return this->_roomNumber;
}

void Room::SetSide(Direction d, class MapSite *ms) {
	this->_sides->PutAt(d,ms);
}

void Room::Enter() {
	/* Um Code erweitern, falls Maze fuer Spiel verwendet wird */
}

void Room::Print(int indent) {
	PrintIndent(indent);
	printf("Room:\n");
	
	PrintIndent(indent+2);
	printf("_roomNumber = %d\n",this->_roomNumber);
	
	PrintIndent(indent+2);
	if(this->_sides) {
		printf("_sides:\n");
		this->_sides->Print(indent+2);
	} else {
		printf("_sides = NULL\n");
	}
	
	MapSite::Print(indent+2);
}

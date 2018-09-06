#include "Maze.h"
#include "ObjectArray.h"
#include "Room.h"

//---- Maze ---------------------------------------------------------

Maze::Maze() : Object()
{
    this->Rooms = new ObjectArray();
}

Maze::~Maze()
{
    delete this->Rooms;
}

void Maze::AddRoom(class Room * room) {
    this->Rooms->PutAt(room->GetRoomNo(),room);
}

class Room * Maze::RoomNo(int roomNo) const {
    class Room *aRoom;
    aRoom = (class Room *) this->Rooms->GetAt(roomNo); 
    return aRoom;
}

void Maze::Print(int indent) {
    PrintIndent(indent);
    printf("Maze:\n");

    PrintIndent(indent+2);
    if (this->Rooms) {
        printf("Rooms = \n");
        this->Rooms->Print(indent+4);
    } else {
        printf("Rooms = NULL\n");
    }

    Object::Print(indent+2);
}

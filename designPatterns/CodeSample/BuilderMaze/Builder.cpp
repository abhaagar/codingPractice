#include "Builder.h"
#include "MazeGame.h"
/*
*/
#include "Maze.h"
#include "Wall.h"
#include "Room.h"
#include "Door.h"
/*
*/


/*
*/
StandardMazeBuilder::StandardMazeBuilder () {
    _currentMaze = 0;
}
/*
*/
void StandardMazeBuilder::BuildMaze () {
    _currentMaze = new Maze;
}
/*
*/
Maze *StandardMazeBuilder::GetMaze () {
    Maze* maze =  _currentMaze;
    return maze;
}
/*
*/
void StandardMazeBuilder::BuildRoom (int n) {
    if (!_currentMaze->RoomNo(n)) {
        Room* room = new Room(n);
        _currentMaze->AddRoom(room);
        /*
        */
        room->SetSide(North, new Wall);
        room->SetSide(South, new Wall);
        room->SetSide(East, new Wall);
        room->SetSide(West, new Wall);
    }
}
/*
*/
void StandardMazeBuilder::BuildDoor (int n1, int n2) {
    Room* r1 = _currentMaze->RoomNo(n1);
    Room* r2 = _currentMaze->RoomNo(n2);
    Door* d = new Door(r1, r2);
    /*
    */
    r1->SetSide(CommonWall(r1,r2), d);
    r2->SetSide(CommonWall(r2,r1), d);
}

/*
*/
CountingMazeBuilder::CountingMazeBuilder () {
    _rooms = _doors = 0;
}
/*
*/
void CountingMazeBuilder::BuildRoom (int) {
    _rooms++;
}
/*
*/
void CountingMazeBuilder::BuildDoor (int, int) {
    _doors++;
}
/*
*/
void CountingMazeBuilder::GetCounts (
                                     int& rooms, int& doors
                                     ) const {
                                         rooms = _rooms;
                                         doors = _doors;
}

void CountingMazeBuilder::BuildMaze ()
{
    // just a stub
}

void CountingMazeBuilder::AddWall(int, Direction)
{
    // TODO:
    // just a stub
}

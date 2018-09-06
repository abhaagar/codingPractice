#ifndef _Builder_h_
#define _Builder_h_

#include "Maze.h"
/*
*/
class Wall;
class Room;
class Door;

class MazeBuilder {
public:
    virtual void BuildMaze() { }
    virtual void BuildRoom(int room) { }
    virtual void BuildDoor(int roomFrom, int roomTo) { }

    virtual Maze* GetMaze() { return 0; }
protected:
    MazeBuilder() {}
};

class StandardMazeBuilder : public MazeBuilder {
public:
    StandardMazeBuilder();
    /*
    */
    virtual void BuildMaze();
    virtual void BuildRoom(int);
    virtual void BuildDoor(int, int);
    /*
    */
    virtual Maze* GetMaze();
private:
    Direction CommonWall(Room*, Room*)
    {
        //TODO
        //CommonWall is a utility operation that determines
        //the direction of the common wall between two rooms
        return East;
    }
    Maze* _currentMaze;
};

/*
*/
class CountingMazeBuilder : public MazeBuilder {
public:
    CountingMazeBuilder();
    /*
    */
    virtual void BuildMaze();
    virtual void BuildRoom(int);
    virtual void BuildDoor(int, int);
    virtual void AddWall(int, Direction);
    /*
    */
    void GetCounts(int&, int&) const;
private:
    int _doors;
    int _rooms;
};

#endif

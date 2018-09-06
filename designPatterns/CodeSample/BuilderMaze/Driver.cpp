#include "MazeGame.h"
#include "Maze.h"
#include "Builder.h"

/*
*/
void create_standard_maze() {
    /*
    */
    Maze* maze;
    MazeGame game;
    StandardMazeBuilder builder;

    game.CreateMaze(builder);
    maze = builder.GetMaze();
    /*
    */
}
/*
*/
void create_counting_maze() {
    /*
    */
    int rooms, doors;
    MazeGame game;
    CountingMazeBuilder builder;

    game.CreateMaze(builder);
    builder.GetCounts(rooms, doors);

    std::cout << "The maze has "
        << rooms << " rooms and "
        << doors << " doors" << std::endl;
    /*
    */
}
/*
*/
int main() {
    create_standard_maze();
    create_counting_maze();
    return 0;
}

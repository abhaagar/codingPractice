#include "MazeGame.h"
#include "Maze.h"
#include "Singleton.h"

int main () {
    Maze * aMaze = 0;

    MazeGame * aGame = new MazeGame();
    MazeFactory *aFactory; aFactory = FactoryInstance( BOOL_ABSTRACT_FACTORY_BOMBED );

    if (aFactory) {
        aMaze = aGame->CreateMaze(aFactory);

        aMaze->Print();
    }

    delete aGame;	aGame = 0;
    delete aFactory; aFactory = 0;
};

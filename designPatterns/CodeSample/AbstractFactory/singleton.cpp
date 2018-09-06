#include "Singleton.h"
#include "BombedMazeFactory.h"

#include "string.h"

class MazeFactory * factoryInstance;

//ik added bombed_ parameter:
class MazeFactory * FactoryInstance( bool bombed_ ) {
    int i = 0;

    if(factoryInstance == 0) {
        if ( bombed_ ) {
            factoryInstance = new BombedMazeFactory();
        } else {
            factoryInstance = new MazeFactory();;
        }
    }
    return factoryInstance;
}

class MazeFactory * FactoryInstance() {
    return FactoryInstance( false );
}


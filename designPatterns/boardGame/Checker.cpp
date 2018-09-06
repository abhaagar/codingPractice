#include "Game.cpp"

class CheckerGame : public Game {
   public:
      CheckerGame(int players,int piecesForEach,int turn,int xDimension, int yDimension) :
         Game(players,piecesForEach,turn,Board(xDimension,yDimension)) {}

      Location* potentialLocationOfOpenantPiece(const Location &from, const Location &to) {
         int x;
         int y;
         if(to.x()>from.x()) {
            x = to.x()-1;
         } else {
            x = to.x()+1;
         }
         if(to.y()>from.y()) {
            y = to.y()-1;
         } else {
            y = to.y()+1;
         }
         return new Location(x,y);
      }
      bool isToLocationFree(Location to) {
         return true;
      }
      void removePieceIfNeeded(const Location &from,const Location &to) {
         if(from.x()-to.x()==1&&from.y()-to.y()) {

         } else {
            Location *openantLocation = potentialLocationOfOpenantPiece(from,to);
            
         }

      }

      void acceptMove(int player,Location from, Location to) {
         std::vector<CheckerPiece>::iterator it = this->pieces.begin();
         if(!this->isToLocationFree(to)) {
            cout << "To Location is not free" << std::endl;
            return;
         }
         for(;it<pieces.end();++it) {
            if(it->isLive()&&it->current()==from)
              break;
         }
         if(!(it-pieces.begin()<this->piecesForEach()&&this->turn()==0 || 
            it-this->pieces.begin()>this->piecesForEach()&&this->turn()==1)) {
            cout << "Piece does not belong to the current player" << std::endl;
            return;
         }

         if(it->isValidMove(from,to)) {
            it->currentIs(to);
            this->removePieceIfNeeded(from,to);
            this->turnIs((turn()+1)%2);
         } else {
            cout << "Invalid Move" << std::endl;
            return;
         }
      }

      void setup() {
         this->addPieces();
         this->setupPiecesLocation();
      }

      void addPieces() {
          for(int i=0; i<this->players();++i) {
             for(int j=0; j<this->piecesForEach(); ++j) {
                if(i==0) {
                   this->pieces.push_back(CheckerPiece("Player 1",WHITE));  
                } else {
                   this->pieces.push_back(CheckerPiece("Player 2",BLACK));
                }
                this->pieces.back().makeLive();
             }
          }
      }

      void setupPiecesLocation() {
          int dimension = this->gameXDimension();
          for(int i=0; i<this->players();++i) {
             int row = i*dimension,col = (row+1)%2;
             for(int j=0; j<this->piecesForEach(); ++j) {
                Location location(row,col);
                this->pieces[i*this->piecesForEach()+j].currentIs(location);
                col = col+2;
                if(col>dimension){
                   i==0?++row:--row;
                   col = (row+1)%2;
                }
             }
          }
      }
   private:
      std::vector<CheckerPiece> pieces;
};

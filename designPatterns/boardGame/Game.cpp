#include"Common.h"
#include"Board.cpp"
#include"Piece.cpp"
class Game {
   public:
      Game(int players,int piecesForEach,int turn,Board board) :
         _players(players),_piecesForEach(piecesForEach),_turn(turn),_board(board) {}

      int gameXDimension() {
         return this->_board.xSquare();
      }
      int players() {
         return this->_players;
      }
      int piecesForEach() {
         return this->_piecesForEach;
      }
      int turn() {
         return this->_turn;
      }
      void turnIs(int turn) {
         this->_turn = turn;
      }
      virtual void addPieces() = 0;
      virtual void setupPiecesLocation() = 0;
      virtual void acceptMove(int player,Location from, Location to) = 0;
      virtual void removePieceIfNeeded(Location from,Location to) = 0;
   private:
      int _players;
      int _piecesForEach;
      int _turn;
      Board _board;
};



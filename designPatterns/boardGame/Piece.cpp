#include "Common.h"
class Boundary {
   public:
      Boundary(int xLimit, int yLimit): _xLimit(xLimit),_yLimit(yLimit) {}
      Boundary(const Boundary &b) {
         this->_xLimit = b.xLimit();
         this->_yLimit = b.yLimit();
      }
      int xLimit() const {
         return this->_xLimit;
      }
      int yLimit() const {
         return this->_yLimit;
      }
   private:
      int _xLimit;
      int _yLimit;
};

class Location {
    public: 
       bool operator==(const Location &s) {
          return this->x()==s.x() && this->y()==s.y();
       }
       Location(int x, int y): _x(x), _y(y) {}
       Location():_x(0),_y(0) {}
       Location(const Location &l) {
          this->_x = l.x();
          this->_y = l.y();
       }
       int x() const {
          return this->_x;
       }
       int y() const {
          return this->_y;
       }
    private:
       int _x;
       int _y;
};

class Move {
   public:
      Move(int xGradient,int yGradient,int xLimit,int yLimit) :
         _xGradient(xGradient),_yGradient(yGradient),_xLimit(xLimit),_yLimit(yLimit) {}
      int xGradient() const {  
         return this->_xGradient;
      }
      int yGradient() const {
         return this->_yGradient;
      }
      int xLimit() const {
         return this->_xLimit;
      }
      int yLimit() const {
         return this->_yLimit;
      }
      bool isXReachable(int xMove) {
         if(this->_xLimit>0) {
            return (this->_xGradient==0&&xMove==0) || (xMove*this->_xGradient>0&&xMove*this->_xGradient<=this->_xLimit);
         } else {
            return (this->_xGradient==0&&xMove==0) || (xMove*this->_xGradient>0);
         }
      }
      bool isYReachable(int yMove) {
         if(this->_yLimit>0) {
            return (this->_yGradient==0&&yMove==0) || (yMove*this->_yGradient>0&&yMove*this->_yGradient<=this->_yLimit);
         } else {
            return (this->_yGradient==0&&yMove==0) || (yMove*this->_yGradient>0);
         }
      }
      bool isReachable(const Location &cl,const Location &tl) {
          int xMove = cl.x()-tl.x();
          int yMove = cl.y()-tl.y();
          return isXReachable(xMove) && isYReachable(yMove);
      }
   private:
      int _xGradient;
      int _yGradient;
      int _xLimit;
      int _yLimit;
};

class Piece {
   public:
      Piece(std::string l,Color c) {
         this->_label = l;
         this->_color = c;
      }
      bool isValidMove(const Location &cl,const Location &tl) {
         for(auto & move : this->_validMoves) {
            if(move.isReachable(cl,tl))
               return true;
         }
         return false;
      }
      void addMove(Move m) {
         this->_validMoves.push_back(m);
      }
      Location current() {
         return this->_current;
      }
      void currentIs(Location current) {
         this->_current = current;
      }
      bool isLive() {
         return this->_isLive;
      }
      void makeLive() {
         this->_isLive = true;
      }
      void makeDead() {
         this->_isLive = false;
      }
   private:
      std::string _label;
      Color _color;
      Location _current;
      std::vector<Move> _validMoves;
      bool _isLive;
};

class CheckerPiece : public Piece {
   public:
      CheckerPiece(std::string label,Color color) : Piece(label,color) {
         this->addAllValidMoves();
      }
      void addAllValidMoves() {
         this->addMove(Move(1,1,2,2));
         this->addMove(Move(-1,1,2,2));
         this->addMove(Move(1,-1,2,2));
         this->addMove(Move(-1,-1,2,2));
      } 
};

class CheckerKing : public Piece {
   public:
      CheckerKing(std::string label,Color color) : Piece(label,color) {
         this->addAllValidMoves();
      }
      void addAllValidMoves() {
         this->addMove(Move(1,1,-1,-1));
         this->addMove(Move(-1,1,-1,-1));
         this->addMove(Move(1,-1,-1,-1));
         this->addMove(Move(-1,-1,-1,-1));
      } 
};

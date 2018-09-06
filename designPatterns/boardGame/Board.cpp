#include "Common.h"
class Square {
   private:
      Square(int x,int y,Color c): _x(x),_y(y),_color(c) {}
      int x() {
         return this->_x;
      }
      int y() {
         return this->_y;
      }
      Color color() {
         return this->_color;
      }
   private:
      int _x;
      int _y;
      Color _color;     
};

class Board {
   public:
      Board(int x,int y) : _xSquare(x),_ySquare(y) {}
      int xSquare() {
         return this->_xSquare;
      }  
      int ySquare() {
         return this->_ySquare;
      }  
   private:
      int _xSquare;
      int _ySquare;

};

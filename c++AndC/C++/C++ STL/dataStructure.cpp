#include<string>
using namespace std;
class Coordinate {
   private:
      int _x;
      int _y;
   public:
      Coordinate(int x, int y): _x(x),_y(y) {}
      bool operator==(const Coordinate &c) {
         return _x==c.x() && _y==c.y();
      }
      bool operator<(const Coordinate &c) const{
         return _x+_y<c.x()+c.y();
      }
      int x() const {
         return _x;
      }
      int y() const {
         return _y;
      }
};

class Mosquito {
   private:
      string _name;
   public:
      Mosquito(string name): _name(name) {}
      string name() {
         return _name;
      }
};




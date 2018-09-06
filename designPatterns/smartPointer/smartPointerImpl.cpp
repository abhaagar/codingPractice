class Reference {
   public:
      int incRefCount() {
         return ++refCount;
      }
      void decRefCount() {
         return --refCount;
      }
      Reference() : refCount(1) {}
   private:
      int refCount;
};


class Location : public Reference {
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


class SmartPointer {
   public:
      SmartPointer( Location *obj = NULL) {
         this->obj = obj;
         obj->incRefCount();
      }
      Location &operator*() {

      }
      Location *operator->() {
         obj
         return obj;
      }

   private:
      Location *obj;
};

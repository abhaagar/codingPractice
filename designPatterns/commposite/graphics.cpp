#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Graphic {
   private:
      string _name;
   public:
      Graphic(string name_) {
         _name = name_;
      }
      void virtual draw() {
         cout << "Graphic \n";
      }
      string name() {
         return _name;
      }
};

class Line : public Graphic {
    public:
       Line(string name_): Graphic(name_) {
       }
       void draw() {
          cout << "  Line: " << name() << "\n";
       } 
};

class Text : public Graphic {
    public:
       Text(string name_): Graphic(name_) {
       }
       void draw() {
          cout << "  Text: " << name() << "\n";
       } 
};

class Image : public Graphic {
    private:
       vector<Graphic *> _elements;
    public:
       Image(string name_): Graphic(name_) {
       }
       void draw() {
          cout << "Image: " << name() << "\n";
          for(vector<Graphic*>::iterator it = _elements.begin(); it!=_elements.end();++it) {
             (*it)->draw();
          }
       } 
       void add(Graphic *g_) {
          _elements.push_back(g_);
       } 
};

int main() {
   Line l1("line1");
   Line l2("line2");
   Text t1("text1");
   Text t2("text2");
   Image i1("Image1");
   Image i2("Image2");
   i1.add(&l1);
   i1.add(&l2);
   i1.add(&t1);
   i2.add(&i1);
   i2.add(&t2);
   i2.draw();
   return 0;
}

#include<iostream>
using namespace std;
class Widget {
 public:
  virtual void draw() = 0;
};

class LinuxButton : public Widget {
 public:
  void draw() { cout << "LinuxButton\n"; }
};
class LinuxMenu : public Widget {
 public:
  void draw() { cout << "LinuxMenu\n"; }
};

class WindowsButton : public Widget {
 public:
  void draw() { cout << "WindowsButton\n"; }
};
class WindowsMenu : public Widget {
 public:
  void draw() { cout << "WindowsMenu\n"; }
};

class Window {
   private:
      Widget *_button;
      Widget *_menu;
   public:
      void buttonIs(Widget *button_) {
         _button = button_;
      }
      void menuIs(Widget *menu_) {
         _menu = menu_;
      }
      void draw() {
         _button->draw();
         _menu->draw();
      }
};

class Builder {
   public:
      virtual Widget* button() = 0;
      virtual Widget* menu() = 0;
};

class LinuxBuilder : public Builder {
   public:
      Widget* button() {
         return new LinuxButton;
      }
      Widget* menu() {
         return new LinuxMenu;
      }
};

class WindowsBuilder : public Builder {
   public:
      Widget* button() {
         return new WindowsButton;
      }
      Widget* menu() {
         return new WindowsMenu;
      }
};

class Director {
   private:
      Builder * _builder;
   public:
      void builderIs(Builder *builder_) {
         _builder = builder_;
      }
      void createWindow() {
         Window *w = new Window;
         w->buttonIs(_builder->button());
         w->menuIs(_builder->menu());
         w->draw();
      }
};


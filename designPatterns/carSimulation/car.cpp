#include<iostream>
#include<math.h>
#include<exception>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<math.h>
#include<ctime>
using namespace std;
class Tyre {
   private:
      int rpm;
      int pressure;
   public:
      Tyre(int rpm=0,int pressure=100) : rpm(rpm),pressure(pressure) {
          if(!(this->rpm>=0 && this->pressure>=0)) {
             //throw std::out_of_range;
          }
      }

      int speed() {
         return this->rpm;
      }
      
      void speedUp(int step) {
         this->rpm += step;
         cout << "Speed increased by " << step;
         cout << " Current speed is " << this->rpm << std::endl;
      }

      void speedDown(int step) {
         this->rpm -= step;
         if(this->rpm<0) {
            this->rpm = 0;
            cout<< "Speed becomes zero" << std::endl;
         } else {
            cout<< "Speed decreased by " << step;
            cout << " Current speed is " << this->rpm << std::endl;
         }
      }
      bool isMaxCrossing() {
         return this->rpm>100;
      }
      bool isStopped() {
         return  this->rpm==0;
      }
      int getPressure() {
         return pressure;
      }
      void setPressure(int pressure) {
          if(pressure>=0) 
             this->pressure = pressure;
      }
      bool isFlat() {
         return this->pressure==0;
      }
};

class Light {
   private:
      bool status;
   public:
      void switchOn() {
         this->status = true;
      }
      void switchOff() {
         this->status = false;
      }
      bool isOn() {
         return this->status;
      }
};

class Horn {
   private:
      bool status;
   public:
      void push();
};


class Engine {
   private:
      Tyre* tyres;
      int state;
   public:
      void setTyre(Tyre *tyres) {
         this->tyres = tyres; 
      }
      void start() {
         this->state = 1;
      }
      void stop() {
         this->state = 0;
      }
      void applyBrake(int step) {
         if(!this->state)
            return;
         this->tyres->speedDown(step);
      }
      void accelerate(int step) {
         if(!this->state)
            return;
         this->tyres->speedUp(step);
      }
      void switchOff() {
         this->tyres->speedDown(10000);
      }
};
class Car {
   public:
      void startSimulation() {
         this->prepare();
         (this->engine).start();
         (this->engine).accelerate(50);
         while(true) {
            int action = rand()%2; 
            if(action==0) {
               (this->engine).accelerate(3);
               if(this->isOverSpeeding()) {
                  cout << "Slowing down the speed since car is overspeeding" << std::endl;
                  (this->engine).applyBrake(5);
               }
            } else {
               (this->engine).applyBrake(3);
               if((this->tyres).isStopped()) {
                  cout << "Car is stopped....Exiting" << std::endl;
                  this->switchOff();
                  exit(0);
               }
            }
            int currentAir = (this->tyres).getPressure();
            this->decreaseAir();
            if((this->tyres).isFlat()) {
               cout << "Tyres are flat....Exiting" << std::endl;
               this->switchOff();
               exit(0);
            }
            sleep(1);
            if(this->isEveningTime() && !(this->lights).isOn()) {
                (this->lights).switchOn();
                cout << "Its evening time so switching on the light\n";
            } else if(!this->isEveningTime() && (this->lights).isOn()) {
                (this->lights).switchOff();
                cout << "Its morning time so switching off the light\n";
            }
         }
      }

   private:
      Light lights;
      Tyre tyres;
      Engine engine;
      void prepare() {
         this->engine.setTyre(&(this->tyres));
      }
      void decreaseAir() {
         int currentAir = (this->tyres).getPressure();
         (this->tyres).setPressure(currentAir-0.05);
      }
      bool isOverSpeeding() {
         return (this->tyres).isMaxCrossing();
      }
      bool isEveningTime() {
         time_t t = time(0);
         int partOfDay = ceil((t%86400)/21600);
         return partOfDay==1||partOfDay==4;
      }
      void switchOff() {
         (this->engine).switchOff();

      }

};


int main() {
   Car car; 
   car.startSimulation();
   return 0;
}

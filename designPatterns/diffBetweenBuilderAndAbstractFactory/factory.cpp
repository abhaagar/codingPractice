enum Type {
  american,
  mexican, 
  italian
};
enum Size {
   small,
   medium,
   large
};
enum Sauce {
   sweet,
   hot
};
enum Meat {
   none,
   bacon,
   chicken
};
enum Crust {
   thin,
   bulk
};
class Pizza {
   private:
      Type _type;
      Size _size;
      Sauce _sauce;
      Meat _meat;
      Crust _crust;
};
class AmericanPizza : public Pizza {
   public:
      AmericanPizza() {
         _type = american;
         _size = medium;
         _sauce = hot;
         _meat = chicken;
         _crust = bulk;
      }
};

class MexicanPizza : public Pizza {
   public:
      AmericanPizza() {
         _type = mexican;
         _size = medium;
         _sauce = sweet;
         _meat = bacon;
         _crust = thin;
      }
};

class Factory {


}


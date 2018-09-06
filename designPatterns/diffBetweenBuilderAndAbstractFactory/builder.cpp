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
   public:
      void typeIs(Type type_) {
         _type == type_;
      }  
      void sizeIs(Size size_) {
         _size = size_;
      }
      void sauceIs(Sauce sauce_) {
         _sauce = sauce_;
      }
      void meatIs(Meat meat_) {
         _meat = meat_;
      }
      void crustIs(Crust crust_) {
         _crust = crust_;
      }
};

class Builder {
   public:
      virtual Type type() = 0;
      virtual Size size() = 0;
      virtual Sauce sauce() = 0;
      virtual Meat meat() = 0;
      virtual Crust crust() = 0;
};

class AmericanBuilder : public Builder {
   public:
      Type type() {
         return american;
      }

      Size size() {
         return medium;
      }

      Sauce sauce() {
         return hot;
      }

      Meat meat() {
         return chicken;
      }
      
      Crust crust() {
         return thin;
      }
};

class MexicanBuilder : public Builder {
   public:
      Type type() {
         return mexican;
      }

      Size size() {
         return medium;
      }

      Sauce sauce() {
         return sweet;
      }

      Meat meat() {
         return bacon;
      }
      
      Crust crust() {
         return bulk;
      }
};

class Director {
   private:
      Builder *_builder;
   public:
      void builderIs(Builder *builder_) {
         _builder = builder_;
      }
      void createPizza() {
         Pizza *pizza = new Pizza;
         pizza->typeIs(_builder->type());
         pizza->sizeIs(_builder->size());
         pizza->sauceIs(_builder->sauce());
         pizza->meatIs(_builder->meat());
         pizza->crustIs(_builder->crust());
      }
};
int main() {
   Director d;
   d.builderIs(new MexicanBuilder);
   d.createPizza();
   return 0;
}

#include<string>
#include<iostream>

using namespace std;

class Exception {

}

class Address {
   private:
      string houseInfo;
      string streetInfo;
      string areaInfo;
      string city;
      string state;
      int pincode;
   public:
      void setHouseInfo(string info);
      void setStreetInfo(string info); 
      void setAreaInfo(string info);
      void setCity(string city);
      void setState(string state);
      void setPincode(int pin);
      string setHouseInfo();
      string setStreetInfo(); 
      string setAreaInfo();
      string setCity();
      string setState();
      string setPincode();
};

class PhoneNumber {
   private:
      string number;
   public:
      string getNumber() = 0;
      void setNumber() = 0;
      void setNumber(string number) = 0;
};

class Landline : public PhoneNumber {
   private:
      string stdCode;
   public:
      string getNumber();
      void setNumber(string number);
};

class Mobile : public PhoneNumber {
   public:
      string getNumber();
      void setNumber(string number);
};

class Email {
   private:
      string id;
   public:
      void setId(string id);
      string getId();
      bool validate();
};


class FullName {
   private:
      string first;
      string last;
   public:
      FullName(string f,string l): first(f), last(l) {} 
      void setFirst(string first) {
          this->first = name;
      }
      void setLast(string last) {
          this->last = last;
      }
      string getFirst() {
         return this->first;
      }
      string getLast() {
         return this->last;
      }
      bool operator=(FullName const &name1, FullName const &name2) {
         return name1.first==name2.first &&  name1.last==name2.last;
      }
};

class User {
   private:
      FullName name;
      vector<pair<int,Address> > addreses;
      vector<pair<int,PhoneNumber> > phones;
      Email const emailId;
      string const username;
      string passwdHash;
};


class Product {
   private:
      int id;
      string desc;
      const int catId;
      const int vendorId;
      float quantity;
      float price;
   public:
      Product(int id,string desc,int cId,int vId,float q,float p):
         id(id),desc(desc),catId(cId),vendorId(vId),quantity(q),price(p) {
      }   

      ostream& operator<<(ostream& os, const Product& p)  
      {  
         os << p.desc << " " << p.quantity << " " << p.price << std::endl;
      }      

      void setPrice(float price) {
         this->price = price;
      }
      float getPrice() {
         return this->price;
      }
      float getQuantity() {
        return this->quantity;
      }
      void setQuantity(float quanity) {
         if(quantity<0){
            Exception("invald range");
         } else {
           this->quantity = quantity;
         }
      }
      string getDesc() {
         return this->desc;
      }
      void setDesc(string desc) {
         this->desc = desc;
      }
      int getCategoryId() {
         return this->catId;
      }
      int getVendorId() {
         return this->vendorId;
      }
};

class Customer : public User {

};

class Vendor : public User {

};

class Category {
   private:
      string desc;
      int id;
};

class Counter {

};

class Store {
   private:
      vector<pair<int,Category> > cats;
      vector<pair<string,User> > users;
      vector<pair<int,Product> > products;
      int userIdCounter;
      int catgoryIdCounter;
      int productIdCounter;
   public:
      void addUser();
      void deleteUser(string username);
      void modifyUser(string userName,User updatingUser);
      vector<User> getUsers();
      vector<Product> searchProducts(string pattern);
      vector<Product> searchProducts(int catId);
      void buyProduct(int pId,float quantity);
      void addProduct(Product);
      void deleteProduct(User *user,Product);
      void modifyProduct(User *user,Product);
      void addCategory(Category &cat); 
      void deleteCategory(Category &cat); 
      void modifyCategory(Category &cat); 
      vector<Category> getCategories();
};

vector<User> getUsers() {
   vector<User> users;
   for(vector<pair<string,User> >::iterator it = users.begin(); it<users.end(); ++it) {
      users.push_back((*it).second);
   }
   return users;
}

void
Store::addUser(User user) {
   for(vector<pair<string,User> >::iterator it = users.begin(); it<users.end(); ++it) {
      if((*it).first==user.name){
          Exception("existing user");
      }
   }
   users.push_back(make_pair(user.emailId,user));
}

void
Store::deleteUser(string userName) {
   vector<pair<string,User> >::iterator it = users.begin();
   for(;it<users.end(); ++it) {
      if((*it).first==user.name){
          break
      }
   }
   if(it!=users.end()) {
      users.erase(it,it+1);
   } else {
      Exception("Non Existing User");
   }
}

void
Store::updateUser(User user) {
   vector<pair<string,User> >::iterator it = users.begin();
   for(;it<users.end(); ++it) {
      if((*it).first==user.name)
         break;
   }
   if(it!=users.end()) {
      users.erase(it,it+1);
      users.push_back(make_pair(user.name,user));
   } else {
      Exception("Non Existing User");
   }
}

vector<Product> Store::searchProducts(string pattern) {
   vector<Product> result;
   for(vector<pair<int,Product> >::iterator it = products.begin(); it<products.end(); ++it) {
      if((*it).first.getDesc().find(pattern)!=string::npos)
         result.push_back((*it).second);
   }
   return result; 
}

vector<Product> Store::searchProducts(int catId) {
   vector<Product> result;
   for(vector<pair<int,Product> >::iterator it = products.begin(); it<products.end(); ++it) {
      if((*it).second.getCategoryId()==catId)
         result.push_back((*it).second);
   }
   return result; 
}

void Store::buyProduct(int pId, float quantity) {
       
}


vector<Category> getCategories() {
   vector<Category> catgs;
   for(vector<pair<int,Category> >::iterator it = cats.begin(); it<cats.end(); ++it) {
      catgs.push_back((*it).second); 
   }
   return catgs;
}

void addCategory(int catId,Category catg) {
   vector<pair<int,Category> >::iterator it = cats.begin();
   for(; it<cats.end(); ++it) {
      if((*it).first==catId)
         break;
   }
   if(it!=cats.end()) {
      cats.push_back(make_pair(catId,catg));
   } else {
      Exception("category already existing");
   }
}


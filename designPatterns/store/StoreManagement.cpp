#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
class Category {
   public:
      
};

class Item {
   private:
      string _name;
      vector<string> _categories;
};

class Transaction {
   public:
      int time();
      string category(); 
      string name();
      int count();
      float price();
      float value();
   private:
      const int _time;
      const string _category;
      const string _name;
      const int _count;
};
int Transaction::time() {
   return _time;
}
string Transaction::category() {
   return _category;
}
string Transaction::name() {
   return _name;
}
int Transaction::count() {
   return _count;
}
class Inventory {
   public:
      void addItem(string,int);
      bool removeItem(string,int);
      int stockLeft(string item_);
   private:
      unordered_map<string,int> _stock;
      bool doesItemExist(string name_);
};
bool Inventory::doesItemExist(string name_) {
   return _stock.find(name_)!=_stock.end();
}

void Inventory::addItem(string name_, int count_) {
   if(!doesItemExist(name_))
      _stock[name_] = 0;
   _stock[name_] += count_;
}
bool Inventory::removeItem(string name_,int count_) {
   if(!doesItemExist(name_)) {
      cout<<"Item does not exist "+name_ << endl;
      return false;
   }
   if(_stock[name_]<count_) {
      cout << "Insufficient stock left\n";
      return false;
   }
   _stock[name_] -= count_; 
}
int Inventory::stockLeft(string name_) {
   if(doesItemExist(name_))
      return _stock[name_];
   return 0;
}
class Store {
   public:
      //int unitSoldForCategory(int, int,string);
      int unitSoldForItem(int,int,string);
      int unitSold(int, int);
      int stockLeft(string);
      void loadItem(string, int);
      bool purchaseItem(string,int);
      Store(string name_): _name(name_) {}
   private:
      unordered_map<string, vector<Transaction*> > _transactions;
      Inventory _inventory;
      string _name;
};

//int Store::unitSoldForCategory(int from_, int to_, string category_);
int Store::unitSoldForItem(int from_, int to_, string name_) {
   int sale=0;
   if(_transactions.find(name_)==_transactions.end())
      return sale;
   for(int i=0; i<_transactions[name_].size();++i) {
      if(_transactions[name_][i]->time()>=from_ && 
         _transactions[name_][i]->time()<=to_ && 
         _transactions[name_][i]->name()==name_)
         sale += _transactions[name_][i]->count();
   }
   return sale;
}
int Store::unitSold(int from_, int to_) {
   float sale=0;
   unordered_map<string, vector<Transaction*> >::iterator it = _transactions.begin();
   for(;it!=_transactions.end();++it) {
      for(int j=0; j<(it->second).size();++j) {
         if((it->second)[j]->time()>=from_ && (it->second)[j]->time()<=to_)
            sale += (it->second)[j]->count();
      }
   }
   return sale;
}
int Store::stockLeft(string name_) {
   return _inventory.stockLeft(name_);
}
void Store::loadItem(string name_, int count_) {
   _inventory.addItem(name_,count_);
}
bool Store::purchaseItem(string name_,int count_) {
   return _inventory.removeItem(name_,count_);
}

class CityStores {
   public:
      int unitSoldForItem(int,int,string,string);
      int unitSold(int,int,string);
      int stockLeft(string,string);
      void loadItem(string,string, int);
      bool purchaseItem(string,string,int);
      void addStore(string name_);
      CityStores(string name_):  _name(name_) {}
   private:
      unordered_map<string, Store*> _stores;
      bool doesStoreExist(string);
      string _name;
};
bool CityStores::doesStoreExist(string name_) {
   return _stores.find(name_)!=_stores.end();
}
void CityStores::addStore(string name_) {
   if(!doesStoreExist(name_)) {
      _stores[name_] = new Store(name_);
   } else {
      cout << "store already exists: "+name_<<endl;  
   }
}
bool CityStores::purchaseItem(string name_,string item_,int count_) {
   if(!doesStoreExist(name_)) {
      cout << "store does not exist\n";
      return false;
   }
   return _stores[name_]->purchaseItem(item_,count_);
}
void CityStores::loadItem(string name_,string item_, int count_) {
   if(!doesStoreExist(name_)) {
      cout << "store does not exist\n";
      return;
   }
   _stores[name_]->loadItem(item_,count_);
}

int CityStores::stockLeft(string name_,string item_) {
   if(!doesStoreExist(name_)) {
      cout << "store does not exist\n";
      return 0;
   }
   return _stores[name_]->stockLeft(item_);
}
int CityStores::unitSold(int from_, int to_,string name_) {
   int sale=0;
   unordered_map<string, Store*>::iterator it = _stores.begin();
   for(; it!=_stores.end();++it) {
      sale += it->second->unitSold(from_,to_);
   } 
   return sale; 
}
int CityStores::unitSoldForItem(int from_, int to_,string name_,string item_) {
   int sale=0;
   unordered_map<string, Store*>::iterator it = _stores.begin();
   for(int i=0; i<_stores.size();++i) {
      sale += it->second->unitSoldForItem(from_,to_,item_);
   } 
   return sale; 
}

class SM {
   public:
      int unitSoldForItem(int,int,string,string,string);
      int unitSold(int,int,string,string);
      int stockLeft(string,string,string);
      void loadItem(string,string,string, int);
      bool purchaseItem(string,string,string,int);
      void addStore(string,string);
   private:
      unordered_map<string, CityStores*> _cityStores;
      bool doesCityStoresExist(string);
};
bool SM::doesCityStoresExist(string name_) {
   return _cityStores.find(name_)!=_cityStores.end();
}

void SM::addStore(string name_,string store_) {
   if(!doesCityStoresExist(name_)) {
      _cityStores[name_] = new CityStores(store_);
   }
   _cityStores[name_]->addStore(store_);
}
bool SM::purchaseItem(string name_,string store_,string item_,int count_) {
   if(doesCityStoresExist(name_)) {
      _cityStores[name_]->purchaseItem(store_,item_,count_);
     return true;
   }
   return false;
}

void SM::loadItem(string name_,string store_,string item_,int count_) {
   if(doesCityStoresExist(name_)) {
      _cityStores[name_]->loadItem(store_,item_,count_);
   }
}
int SM::stockLeft(string name_,string store_,string item_) {
   if(doesCityStoresExist(name_)) {
      return _cityStores[name_]->stockLeft(store_,item_);
   }
   return 0;
}

int SM::unitSold(int from_,int to_,string city_,string store_) {
   if(doesCityStoresExist(city_)) {
      return _cityStores[city_]->unitSold(from_,to_,store_);
   }
   return 0;
}
int SM::unitSoldForItem(int from_, int to_, string city_,string store_, string item_) {
   if(doesCityStoresExist(city_)) {
      return _cityStores[city_]->unitSoldForItem(from_,to_,store_,item_);
   }
   return 0;

}
int main() {
   SM sm;
   sm.addStore("bangalore","relianceTrends");
   sm.addStore("bangalore","marksAndSpencer");
   sm.loadItem("bangalore","relianceTrends","poha",10);
   sm.loadItem("bangalore","marksAndSpencer","bread",10);
   sm.purchaseItem("bangalore","relianceTrends","poha",1);
   sm.purchaseItem("bangalore","marksAndSpencer","bread",1);
   cout << sm.stockLeft("bangalore","relianceTrends","poha") << endl;
   cout << sm.unitSoldForItem("bangalore","relianceTrends","poha");
   return 0;
}

#include<iostream>
#include<unordered_map>
#include<string>
#include<algorithm>
#include<ctime>
#include<vector>
using namespace std;


long int currentEpoch() {
   std::time_t result = std::time(0);
   return result;
}

class Store {
   public:
      void addItem(string name_,int quantity_) {
          // asuuming qutity to be int.
          if(_items.find(name_)==_items.end())
             _items[name_] = 0;
          _items[name_] += quantity_;
          std::cout << quantity_ << " Item " << name_ << " added to store " <<_id << "\n";           
      }
      bool removeItem(string name_,int quantity_) {
          // boll indicates whetehr removal was successfull or not.
          // asuuming qutity to be int.
          if(_items.find(name_)==_items.end())
              return false;
          if(_items[name_]<quantity_)
              return false;
          if(_salesHistory.find(name_)==_salesHistory.end()) {
              vector<pair<int,int> > v;
              _salesHistory[name_] = v;
          } 
          _items[name_] -= quantity_;
          _salesHistory[name_].push_back(make_pair(currentEpoch(),quantity_));
          std::cout << quantity_ <<  " Item " << name_ << " removed from store " <<_id << "\n";           
      }
      int countOfItem(string name_) {
          if(_items.find(name_)==_items.end())
             return 0;
          return _items[name_];
      }

      int getSales(int from_, int to_,string name_) {
         if(_salesHistory.find(name_)==_salesHistory.end())
            return 0;
         vector<pair<int,int> >::iterator it = _salesHistory[name_].begin(); 
         int sales = 0;
         for(; it!=_salesHistory[name_].end();++it)  {
            if(it->first>=from_ && it->first<=to_){
               sales += it->second;
            }
         }
         return sales;
      }
      int getSalesOfAllItems(int from_, int to_) {
         // iteratively calls getSales() for each item
         unordered_map<string,vector<pair<int,int> > >::iterator it = _salesHistory.begin();
         int sales = 0;
         for(; it!=_salesHistory.end();++it) 
            sales += getSales(from_,to_,it->first);
         return sales;
      }

      Store(int id_) : _id(id_) {}
   private:
      int _id;
      unordered_map<string,int> _items;
      unordered_map<string,vector<pair<int,int> > >  _salesHistory;
      // maintain a sales history oof each item
};

class SM {
   public:
      int addStore( string city_, string state_) {
         int id = _storeIdCount;
         ++_storeIdCount;
         Store * store = new Store(id); 
         _allStores[id] = store;
         if(_cityStores.find(city_)==_cityStores.end()) {
           vector<int> v;
            _cityStores[city_] = v;
         }
         _cityStores[city_].push_back(id);
         if(_stateCities.find(state_)==_stateCities.end()) {
            vector<string> v;
            _stateCities[state_] = v;
            _stateCities[state_].push_back(city_);
            return id;
         }
         if(find(_stateCities[state_].begin(),_stateCities[state_].end(),city_)==
            _stateCities[state_].end()){
            _stateCities[state_].push_back(city_);
         }
         return id;
      }
      void addItemInStore(int id_, string name_,int quantity_) {
         if(quantity_<0) {
            std::cout << "Invalid quanity " <<std::endl;
            return ;
         }
         if(!doesStoreExist(id_)) {
            std::cout << "invalid store \n";
            return ;
         }
         _allStores[id_]->addItem(name_, quantity_);
      }
      bool removeItemInStore(int id_, string name_,int quantity_) {
         if(quantity_<0) {
            std::cout << "Invalid quanity " <<std::endl;
            return false;
         }
         if(!doesStoreExist(id_)) {
            std::cout << "invalid store \n";
            return false;
         }
         return _allStores[id_]->removeItem(name_, quantity_);
      }
      int getSalesOfItemInStore(int id_,string name_,int from_, int to_) {
         // get sales of an item given a storeId, name , from , to
         if(!doesStoreExist(id_)) {
            std::cout << "invalid store \n";
            return 0;
         }
         return _allStores[id_]->getSales(from_,to_,name_);
      }
      int getAllSalesInStore(int id_, int from_, int to_) {
         // get sales of all items for a stroe for a period.
         if(!doesStoreExist(id_)) {
            std::cout << "invalid store \n";
            return 0;
         }
         return _allStores[id_]->getSalesOfAllItems(from_,to_);
         
      }
      int getAllSalesOfCity(int from_, int to_,string city_) {
         // iteratiely calls getSalesOfItemInStore() for each city.
         int sales = 0;
         for(vector<int>::iterator it=_cityStores[city_].begin(); it!=_cityStores[city_].end();++it) {
            int id = *it;
            sales += getAllSalesInStore(id,from_,to_);       
         }
         return sales;
      }
      int getAllSalesOfState(int from_, int to_,string state_) {
          vector<string>::iterator it = _stateCities[state_].begin();
          int sales = 0;
          for(; it!=_stateCities[state_].end();++it) {
              sales += getAllSalesOfCity(from_, to_,*it);
          }
          return sales;
 
      }
 
      bool doesStoreExist(int id_) {
         return _allStores.find(id_)!=_allStores.end();
      }
      int stockLeftOfItem(int id_, string name_) {
         return _allStores[id_]->countOfItem(name_);
      }
      SM() {
         _storeIdCount= 0;
         
      }
   public:
      int _storeIdCount;
      unordered_map<string,vector<int>> _cityStores;
      // map of city-> {storeIds}
      unordered_map<string,vector<string> > _stateCities;
      // map of state->{cities}
      unordered_map<int,Store*> _allStores;
      // map of storeId->Store object
      
};


int main() {
   std::cout << "Please use unix epoch for specifying period for various quries \n" << std::endl;
   SM sm;
   cout << "store Id : " << sm.addStore("bangalore","karnataka") << std::endl;
   cout << "store Id : " << sm.addStore("bangalore","karnataka") << std::endl;
   cout << "store Id : " << sm.addStore("mysore","karnataka") << std::endl;
   sm.addItemInStore(0,"Poha",10); 
   sm.addItemInStore(2,"Soap",5); 
   std::cout <<  "Current Stock of Poha in store 0"  << sm.stockLeftOfItem(0,"Poha") << "\n";
   std::cout <<  "Current Stock of Soap in store 0"  << sm.stockLeftOfItem(0,"Soap") << "\n";
   //std::cout <<sm.stockLeftOfItem(0,"Soap") << "\n";
   sm.removeItemInStore(0,"Poha",1); 
   std::cout <<  "Current Stock of Poha in store 0"  << sm.stockLeftOfItem(0,"Poha") << "\n";
   sm.removeItemInStore(0,"Soap",1); 
   //sm.addItemInStore(0,"Soap",1); 
   std::cout <<  "Current Stock of Soap in store 0"  << sm.stockLeftOfItem(0,"Soap") << "\n";
   sm.removeItemInStore(0,"Poha",4); 
   sm.removeItemInStore(0,"Soap",4); 
   std::cout <<  "Current Stock of Poha in store 0"  << sm.stockLeftOfItem(0,"Poha") << "\n";
   std::cout <<  "Current Stock of Soap in store 0"  << sm.stockLeftOfItem(0,"Soap") << "\n";
   std::cout << "removed Item" << sm.removeItemInStore(2,"Soap",4) << "\n" ; 
   //sm.removeItemInStore(2,"Poha",5); 
   std::cout <<sm.getAllSalesOfCity(currentEpoch()-86400,currentEpoch(),"bangalore") << std::endl;
   std::cout <<sm.getAllSalesOfState(currentEpoch()-86400,currentEpoch(),"karnataka") << std::endl;
   std::cout <<sm.removeItemInStore(0,"Poha",100) << std::endl; 
   std::cout <<sm.removeItemInStore(0,"Poha",0) << std::endl; 
   std::cout << sm.stockLeftOfItem(0,"Poha")<< std::endl;
   //std::cout << sm.getSalesOfItemInStore(0,"Poha",currentEpoch()-86400,currentEpoch())<< std::endl;
   //std::cout << sm.getAllSalesOfState(currentEpoch()-86400,currentEpoch(),"karnataka")<< std::endl;
   // initialized with 0 store
   // one can change form and to to get monthlu sales

   return 0;
}


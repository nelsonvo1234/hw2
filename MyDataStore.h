#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include "datastore.h"

class MyDataStore : public DataStore{
    public:
        void addProduct(Product* p);
        void addUser(User* u);
        std::vector<Product*> search(std::vector<std::string>& terms, int type);
        void dump(std::ostream& ofile);
        void addCart(std::string username, Product* p);
        void viewCart(std::string username);
        void buyCart(std::string username);
        ~MyDataStore();
    private:
        User* nameUser(std::string username);
        std::set<User*> users;
        std::set<Product*> products;
        std::map<std::string, std::set<Product*>> keywordMap;
        std::map<User*,  std::queue<Product*>> cartMap;
};

#endif
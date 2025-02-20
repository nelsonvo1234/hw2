#include "mydatastore.h"
#include "util.h"

void MyDataStore::addProduct(Product* p){
    products.insert(p);
    std::set<std::string> keywords = p->keywords();
    std::set<std::string>::iterator keywordIterator;
    for(keywordIterator = keywords.begin(); keywordIterator != keywords.end(); keywordIterator++){
        keywordMap[*keywordIterator].insert(p);
    }
}

void MyDataStore::addUser(User* u){
    users.insert(u);
}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::set<Product*> result;
    std::vector<std::string>::iterator it;
    for(it = terms.begin(); it != terms.end(); it++){
        if(it == terms.begin()){
            result = keywordMap[*it];
        }
        else if(type){
            //OR search
            result = setUnion(result, keywordMap[*it]);
        }
        else{
            //AND search
            
            result = setIntersection(result, keywordMap[*it]);
        }
    }
    return std::vector<Product*>(result.begin(), result.end());
}

void MyDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << std::endl;
    std::set<Product*>::iterator productIt;
    for(productIt = products.begin(); productIt != products.end(); productIt++){
        (*productIt)->dump(ofile);
    }
    ofile << "</products>" << std::endl;

    ofile << "<users>" << std::endl;
    std::set<User*>::iterator userIt;
    for(userIt = users.begin(); userIt != users.end(); userIt++){
        (*userIt)->dump(ofile);
    }
    ofile << "</users>" << std::endl;
}

void MyDataStore::addCart(std::string username, Product* p){
    User* u = nameUser(username);
    if(u == nullptr || p == nullptr){
        std::cout << "Invalid request" << std::endl;
        return;
    }
    cartMap[u].push(p);
}

void MyDataStore::viewCart(std::string username){
    User* u = nameUser(username);
    if(u == nullptr){
        std::cout << "Invalid username" << std::endl;
        return;
    }
    std::queue<Product*> cart = cartMap[u];
    for(int i = 0; i < cart.size(); i++){
        std::cout << i << ": " << cart.front() << std::endl;
        cart.pop();
    }
}

void MyDataStore::buyCart(std::string username){
    User* u = nameUser(username);
    if(u == nullptr){
        std::cout << "Invalid username" << std::endl;
        return;    
    }
    std::queue<Product*>* cart = &cartMap[u];
    int cartSize = cart->size();
    for(int i = 0; i < cart->size(); i++){
        Product* cur = cart->front();
        cart->pop();
        if(cur->getQty() > 0 && u->getBalance() >= cur->getPrice()){
            cur->subtractQty(1);
            u->deductAmount(cur->getPrice());
        }
        else{
            cart->push(cur);
        }
    }
}

User* MyDataStore::nameUser(std::string username){
    for(std::set<User*>::iterator it = users.begin(); it != users.end(); it++){
        if((*it)->getName().compare(username) == 0){
            return *it;
        }
    }
    return nullptr;
}
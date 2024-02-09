#include "mydatastore.h"
#include "util.h"
#include "product.h"
#include <set>
#include <map>
#include <vector>
#include <string>

using namespace std;

MyDataStore::MyDataStore(){

}

MyDataStore::~MyDataStore(){
    for(vector<User*>::iterator it = users_.begin(); it != users_.end(); ++it){
        delete *it;
    }
    users_.clear();
    for(vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
        delete *it;
    }
    products_.clear();
}

/**
 * Adds a product to the data store
 */
void MyDataStore::addProduct(Product* p){
    products_.push_back(p);
    set<string> keys = p->keywords();
    for(set<string>::iterator it = keys.begin(); it != keys.end(); ++it){
        keywordsAndProducts_[*it].insert(p);
    }

}

/**
 * Adds a user to the data store
 */
void MyDataStore::addUser(User* u){
    users_.push_back(u);
    cart_[u->getName()] = vector<Product *>(); //add key to cart
}

/**
 * Performs a search of products whose keywords match the given "terms"
 *  type 0 = AND search (intersection of results for each term) while
 *  type 1 = OR search (union of results for each term)
 */
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> hits;
    if(terms.size() == 0){ //no keywords
        cout << "No keywords entered." << endl;
        return hits;
    }
    if(terms.size() == 1) { //one keyword
        for(set<Product*>::iterator it = keywordsAndProducts_[terms[0]].begin(); it != keywordsAndProducts_[terms[0]].end(); ++it){
            hits.push_back(*it);
        }
        return hits;
    }

    set<Product*> results = keywordsAndProducts_[terms[0]];

    if(type == 0){ //AND search
        for(std::vector<std::string>::iterator it = terms.begin() + 1; it != terms.end(); ++it){
            results = setIntersection(results, keywordsAndProducts_[*it]);
        }
    }
    else if(type == 1){ //OR search
        for(std::vector<std::string>::iterator it = terms.begin() + 1; it != terms.end(); ++it){
            results = setUnion(results, keywordsAndProducts_[*it]);
        }
    }
    for(set<Product*>::iterator it = results.begin(); it != results.end(); ++it){
        hits.push_back (*it);
    }

    return hits;
}

/**
 * Reproduce the database file from the current Products and User values
 */
void MyDataStore::dump(std::ostream& ofile){
    ofile << "<products>" << endl;
    for(vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
        (*it)->dump(ofile);
    }
    ofile << "</products>" << "\n" << "<users>" << endl;
    for(vector<User*>::iterator it = users_.begin(); it != users_.end(); ++it){
        (*it)->dump(ofile);
    }
    ofile << "</users>" << endl;
}

//member functions
void MyDataStore::addCart(std::string username, Product* p){
    User* user = findUser(username);
    if(user == nullptr || p == nullptr){ //invalid
        cout << "Invalid request" << endl;
        return;
    }
    cart_[user->getName()].push_back(p);
}

void MyDataStore::buyCart(std::string username){
    User* user = findUser(username);
    if(user == nullptr){ //invalid
        cout << "Invalid username" << endl;
        return;
    }
    for(std::vector<Product*>::iterator it = cart_[user->getName()].begin(); it != cart_[user->getName()].end(); ++it){
        if((*it)->getQty() > 0 && user->getBalance() > (*it)->getPrice()){ //in stock and enough money
            (*it)->subtractQty(1); //reduce qty by 1
            user->deductAmount((*it)->getPrice()); //price debited from user's credit
            cart_[user->getName()].erase(it); //remove from cart
            --it;
        }
    }
}

void MyDataStore::viewCart(std::string username){
    User* user = findUser(username);
    if(user == nullptr){ //invalid
        cout << "Invalid username" << endl;
        return;
    }
    for(std::vector<Product*>::iterator it = cart_[user->getName()].begin(); it != cart_[user->getName()].end(); ++it){
        cout << "Item " << (std::distance(cart_[user->getName()].begin(), it) + 1) << endl; 
        (*it)->displayString();
        cout << endl;
    }
}

User* MyDataStore::findUser(std::string username){
    for(std::vector<User*>::iterator it = users_.begin(); it != users_.end(); ++it){
        if((*it)->getName() == username){ //if found
            return (*it);
        }
    }
    return nullptr; //user not found
}

Product* MyDataStore::findProduct(std::string name){
    for(std::vector<Product*>::iterator it = products_.begin(); it != products_.end(); ++it){
        if((*it)->getName() == name){ //if found
            return (*it);
        }
    }
    return nullptr; //product not found
}
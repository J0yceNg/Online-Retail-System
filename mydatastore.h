#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "util.h"


/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 * DO NOT EDIT
 */


class MyDataStore : public DataStore{
public:
    MyDataStore();
    virtual ~MyDataStore();

    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile);

    //member functions
    void addCart(std::string username, Product* p);
    void buyCart(std::string username);
    void viewCart(std::string username);
    User* findUser(std::string username);
    Product* findProduct(std::string name);

    //data members
    std::vector<User*> users_;
    std::vector<Product*> products_;
    std::map<std::string, std::set<Product*>> keywordsAndProducts_;
    std::map<std::string, std::vector<Product*>> cart_;
};

#endif

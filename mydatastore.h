#ifndef MYDATASTORE_H
#define MYDATASCORE_H
#include <string>
#include <set>
#include <map>
#include <deque>
#include <utility>
#include <vector>
#include "product.h"
#include "user.h"
/*#include "book.h"
#include "clothing.h"
#include "movie.h"*/
#include "util.h"
#include "datastore.h"
#include "review.h"

class MyDataStore : public DataStore {
public:
    MyDataStore();
    ~MyDataStore();
    void addProduct(Product* p);
    void addUser(User* u);

    std::vector<Product*> search(std::vector<std::string>& terms, int type, char sort);
    void dump(std::ostream& ofile);
    void add_cart(std::string username, Product* item);
    void view_cart(std::string username);
    void buy_cart(std::string username);
    //HMW 5 Update
    void addReview(const std::string& prodName,
               int rating,
               const std::string& username,
               const std::string& date,
               const std::string& review_text);
    bool checkUser(const std::string& name);
    //Need more menu options?

private:
    std::map<std::string, User*> user;
    std::set<Product*> product;
    std::map<std::string, std::set<Product*> > database;
    std::map<std::string, std::deque<Product*> > cart;
    //HMW 5 Update
};
#endif

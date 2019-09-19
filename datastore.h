#ifndef DATASTORE_H
#define DATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "review.h"

/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 */
class DataStore {
public:
    virtual ~DataStore() { }

    /**
     * Adds a product to the data store
     */
    virtual void addProduct(Product* p) = 0;

    /**
     * Adds a user to the data store
     */
    virtual void addUser(User* u) = 0;

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    virtual std::vector<Product*> search(std::vector<std::string>& terms, int type, char sort) = 0;

    /**
     * Reproduce the database file from the current Products and User values
     */
    virtual void dump(std::ostream& ofile) = 0;

    /**
    * Creates and adds a review with the given information
    */
    virtual void addReview(const std::string& prodName,
			   int rating,
			   const std::string& username,
			   const std::string& date,
			   const std::string& review_text) = 0;

};

#endif

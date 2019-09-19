#ifndef BOOK_H
#define BOOK_H
#include "product.h"

class Book : public Product{
public: 
	Book(const std::string isbn, const std::string author, 
		const std::string category, const std::string name, double price, int qty);
	
	~Book();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;
	std::string getISBN();
	std::string getAuthor();

private:
	std::string isbn;
	std::string author;
};
#endif
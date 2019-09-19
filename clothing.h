#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product{
public: 
	Clothing(const std::string size, const std::string brand, 
		const std::string category, const std::string name, double price, int qty);
	
	~Clothing();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;
	std::string getSize();
	std::string getBrand();

private:
	std::string size;
	std::string brand;
};
#endif
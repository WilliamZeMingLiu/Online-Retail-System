#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const string size, const string brand, 
	const std::string category, const std::string name, double price, int qty) : 
	Product(category, name, price, qty), size(size), brand(brand)
{

}

Clothing::~Clothing()
{

}

set<string> Clothing::keywords() const
{
	set<string> keywords;
	set<string> name_keywords;
	set<string> brand_keywords;

	name_keywords = parseStringToWords(Product::getName());
	brand_keywords = parseStringToWords(brand);

	keywords.insert(convToLower(size));
	for(set<string>::iterator it = name_keywords.begin(); it != name_keywords.end(); ++it)
	{
		keywords.insert(*it);
	}
	for(set<string>::iterator it = brand_keywords.begin(); it != brand_keywords.end(); ++it)
	{
		keywords.insert(*it);
	}
	return keywords;
}

string Clothing::displayString() const
{
	string display;
	stringstream ss;
	ss << Product::getPrice() << " " << Product::getQty();
	string str = ss.str();

	display.append(Product::getName());
	display.append("\n");
	display.append("Size: ");
	display.append(size);
	display.append(" Brand: ");
	display.append(brand);
	display.append("\n");
	display.append(str);
	display.append(" left.");
	display.append("\n");
	display.append("Rating: ");
	double sum = 0;
	int count = 0;
	double total = 0;
	std::cout << "REVIEWSIZE:" << review.size() << std::endl;
	if(review.size() == 0)
	{
		sum = 0;
		count = 0;
	}
	else
	{
		for(unsigned i=0; i < review.size(); i++)
		{
			sum += review[i]->rating;
			count++;
		}
	}
	if(sum == 0)
	{
		total = 0;
	}
	else
	{
		total = sum/count;
	}
	
	stringstream xx;
	xx << setprecision(3) << total;
	string rate = xx.str();
	display.append(rate);
	return display;

}

void Clothing::dump(ostream& os) const
{
	Product::dump(os);
	os << size << "\n" << brand << endl;
	return;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}

string Clothing::getSize()
{
	return size;
}
string Clothing::getBrand()
{
	return brand;
}

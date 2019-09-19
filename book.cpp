#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const string isbn, const string author, 
	const std::string category, const std::string name, double price, int qty) : 
	Product(category, name, price, qty), isbn(isbn), author(author)
{

}

Book::~Book()
{

}

set<string> Book::keywords() const
{
	set<string> keywords;
	set<string> name_keywords;
	set<string> author_keywords;

	name_keywords = parseStringToWords(Product::getName());
	author_keywords = parseStringToWords(author);

	keywords.insert(convToLower(isbn));
	for(set<string>::iterator it = name_keywords.begin(); it != name_keywords.end(); ++it)
	{
		keywords.insert(*it);
	}
	for(set<string>::iterator it = author_keywords.begin(); it != author_keywords.end(); ++it)
	{
		keywords.insert(*it);
	}
	return keywords;
}

string Book::displayString() const
{
	string display;
	stringstream ss;
	ss << Product::getPrice() << " " << Product::getQty();
	string str = ss.str();

	display.append(Product::getName());
	display.append("\n");
	display.append("Author: ");
	display.append(author);
	display.append(" ISBN: ");
	display.append(isbn);
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

void Book::dump(ostream& os) const
{
	Product::dump(os);
	os << isbn << "\n" << author << endl;
	return;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}

string Book::getISBN()
{
	return isbn;
}
string Book::getAuthor()
{
	return author;
}

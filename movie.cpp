#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const string genre, const string rating, 
	const std::string category, const std::string name, double price, int qty) : 
	Product(category, name, price, qty), genre(genre), rating(rating)
{

}

Movie::~Movie()
{

}

set<string> Movie::keywords() const
{
	set<string> keywords;
	set<string> name_keywords;

	name_keywords = parseStringToWords(Product::getName());

	keywords.insert(convToLower(genre));
	keywords.insert(convToLower(rating));
	for(set<string>::iterator it = name_keywords.begin(); it != name_keywords.end(); ++it)
	{
		keywords.insert(*it);
	}
	return keywords;
}

string Movie::displayString() const
{
	string display;
	stringstream ss;
	ss << Product::getPrice() << " " << Product::getQty();
	string str = ss.str();

	display.append(Product::getName());
	display.append("\n");
	display.append("Genre: ");
	display.append(genre);
	display.append(" Rating: ");
	display.append(rating);
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

void Movie::dump(ostream& os) const
{
	Product::dump(os);
	os << genre << "\n" << rating << endl;
	return;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const
{
	return false;
}

string Movie::getGenre()
{
	return genre;
}
string Movie::getRating()
{
	return rating;
}
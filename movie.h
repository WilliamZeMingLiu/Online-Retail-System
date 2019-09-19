#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"

class Movie : public Product{
public: 
	Movie(const std::string genre, const std::string rating, 
		const std::string category, const std::string name, double price, int qty);
	
	~Movie();
	std::set<std::string> keywords() const;
	bool isMatch(std::vector<std::string>& searchTerms) const;
	std::string displayString() const;
	void dump(std::ostream& os) const;
	std::string getGenre();
	std::string getRating();

private:
	std::string genre;
	std::string rating;
};
#endif
#include <sstream>
#include <iomanip>
#include "util.h"
#include "mydatastore.h"
#include "msort.h"

using namespace std;

struct R_comp {
  bool operator()(Product* lhs, Product* rhs)
  {
  	return lhs->getName() < rhs->getName();
  }
};

struct L_comp{
	bool operator()(Product* lhs, Product* rhs)
	{
		return lhs->avg_rating > rhs->avg_rating;
	}
};

MyDataStore::MyDataStore()
{

}

MyDataStore::~MyDataStore()
{
	for(map<string, User*>::iterator it = user.begin(); it != user.end(); ++it)
	{
		delete it->second;
	}
	for(set<Product*>::iterator it = product.begin(); it != product.end(); ++it)
	{
		for(unsigned i=0; i < (*it)->review.size(); i++)
		{
			delete (*it)->review[i];
		}
		delete *it;
	}
	//HMW 5 update

}

void MyDataStore::addProduct(Product* p)
{
	this->product.insert(p);

	set<string> keywords = p->keywords();
	for(set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it)
	{
		set<Product*> temp;
		if(database.find(*it) != database.end())
		{
			temp = this->database[*it];
			temp.insert(p);
			this->database[*it] = temp;
		}
		else
		{
			temp.insert(p);
			this->database.insert(make_pair(*it, temp));
		}
	}
	return;
}

void MyDataStore::addUser(User* u)
{
	this->user[u->getName()] = u;
	return;
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type, char sort)
{
	vector<Product*> found_product;
	//Converting to lower case strings
	for(unsigned int i=0; i < terms.size(); i++)
	{
		for(unsigned int j=0; j < terms[i].size(); j++)
		{
			terms[i][j] = tolower(terms[i][j]);
		}
	}

	if (type == 0)
	{
		for(set<Product*>::iterator it = product.begin(); it != product.end(); ++it)
		{
			int unsigned counter = 0;
			set<string> keywords = (*it)->keywords();
			for(unsigned int i=0; i < terms.size(); i++)
			{
				if(keywords.find(terms[i]) != keywords.end())
				{
					counter++;
				}
			}

			if(counter == terms.size())
			{
				found_product.push_back(*it);
			}

		}

	}
	else if(type == 1)
	{
		for(int unsigned i=0; i < terms.size(); i++)
		{
			if(database.find(terms[i]) != database.end())
			{
				for(set<Product*>::iterator it = database[terms[i]].begin(); it != database[terms[i]].end(); ++it)
				{
					//This is assuming that there will be no duplicates
					//for the keyword and object map
					found_product.push_back(*it);
				}
			}
		}

	}

	//Iterate through all products to find if prodName exists
	if(sort == 'r')
	{
		R_comp comp1;
		mergeSort<Product*, R_comp>(found_product, comp1);
	}

	else if(sort == 'n')
	{
		L_comp comp2;
		//vector<Product*> temp;
		
		for(set<Product*>::iterator it=product.begin(); it != product.end(); ++it)
		{
			double sum = 0;
			int count = 0;
			double total = 0;
			for(unsigned i=0; i < (*it)->review.size(); i++)
			{
				if((*it)->review.size() == 0)
				{
					(*it)->avg_rating = 0;
					break;
				}
				sum += (*it)->review[i]->rating;
				count++;
			}
			
			
			total = sum/count;
			(*it)->avg_rating = total;
		}
		mergeSort<Product*, L_comp>(found_product, comp2);
	}
	return found_product;

}
void MyDataStore::dump(ostream& ofile)
{
	ofile << "<products>" << endl;
	for(set<Product*>::iterator it=product.begin(); it != product.end(); ++it)
	{
		(*it)->dump(ofile);
	}
	
	ofile << "</products>" << endl;
	ofile << "<users>" << endl;
	for(map<string, User*>::iterator it=user.begin(); it != user.end(); ++it)
	{
		(it->second)->dump(ofile);
	}
	ofile << "</users>" << endl;

	ofile << "<reviews>" << endl;

	for(set<Product*>::iterator it=product.begin(); it != product.end(); ++it)
	{
		for(unsigned i=0; i < (*it)->review.size(); i++)
		{
			ofile << (*it)->getName() << endl;
			ofile << (*it)->review[i]->rating << " ";
			ofile << (*it)->review[i]->username << " ";
			ofile << (*it)->review[i]->date << " ";
			ofile << (*it)->review[i]->reviewText << endl;
		}
	}
	ofile << "</reviews>" << endl;
	return;
}

void MyDataStore::add_cart(string username, Product* item)
{
	if(user.find(username) != user.end())
	{
		cart[username].push_back(item);
		
	}
	else
	{
		cout << "Invalid request" << endl;
		return;
	}
	return;
}

void MyDataStore::view_cart(string username)
{
	if(user.find(username) == user.end())
	{
		cout << "Invalid username" << endl;
		return;
	}
	for(int unsigned i=0; i < cart[username].size(); i++)
	{
		cout << "Item " << i+1 << endl;
		cout << cart[username][i]->displayString() << endl;
	}
	return;
}

void MyDataStore::buy_cart(string username)
{
	if(user.find(username) == user.end())
	{
		cout << "Invalid username" << endl;
		return;
	}
	deque<Product*> temp;
	for(int unsigned i=0; i < cart[username].size(); i++)
	{
		if(cart[username][i]->getQty() >= 1)
		{
			if(user[username]->getBalance() >= cart[username][i]->getPrice())
			{
				user[username]->deductAmount(cart[username][i]->getPrice());
				cart[username][i]->subtractQty(1);
				temp.push_back(cart[username][i]);

			}
			else
			{
				temp.push_back(cart[username][i]);
			}
		}
		else
		{
			temp.push_back(cart[username][i]);
		}
	}

	cart[username] = temp;
	return;
}

void MyDataStore::addReview(const string& prodName, int rating, 
	const string& username, const string& date, const string& review_text)
	{
		//Iterate through all products to find if prodName exists
		for(set<Product*>::iterator it = product.begin(); it != product.end(); ++it)
		{
			if((*it)->getName() == prodName)
			{
				Review* temp = new Review(rating, username, date, review_text);
				((*it)->review).push_back(temp);
			}
		}
		return;
	}

bool MyDataStore::checkUser(const string& name)
{
	if(user.find(name) == user.end())
	{
		cout << "Invalid user" << endl;
		return true;
	}
	return false;
}
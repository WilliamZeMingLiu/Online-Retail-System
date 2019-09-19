#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include "util.h"
#include "book.h"

using namespace std;

void parseStringToWords_test();
void setIntersection_test();
void setUnion_test();
void book_test();
void mydatastore_test();

int main()
{
	//parseStringToWords_test();
	//setIntersection_test();
	//setUnion_test();
	book_test();
}

void parseStringToWords_test()
{
	string temp = "Men's I'll J. Hello'Dick";
	set<string> keywords;
	keywords = parseStringToWords(temp);
	for (set<string>::iterator it = keywords.begin(); it != keywords.end(); it++) 
	{
   		cout << *it << endl;
	}
	return;
}

void setIntersection_test()
{
	std::set<int> set1;
	std::set<int> set2;
	std::set<int> keywords;

	for(int i=0; i < 10; i++)
	{
		set1.insert(i);
	}
	for(int j=5; j < 15; j++)
	{
		set2.insert(j);
	}

	keywords = setIntersection(set1, set2);
	return;
}

void setUnion_test()
{
	std::set<int> set1;
	std::set<int> set2;
	std::set<int> keywords;

	for(int i=0; i < 10; i++)
	{
		set1.insert(i);
	}
	for(int j=5; j < 15; j++)
	{
		set2.insert(j);
	}

	keywords = setUnion(set1, set2);
	return;
}

void book_test()
{
	Book object = Book("978-013292372-9", "Carrano and Henry", 
		"book", "Data Abstraction & Problem Solving with C++", 
		79.99, 20);

	//object.dump(cout);
	//cout << object.displayString() << endl;

	/*std::set<string> keywords;
	keywords = object.keywords();
	for(typename std::set<string>::iterator it = keywords.begin(); it != keywords.end(); ++it)
	{
		cout << *it << endl;
	}*/

	/*cout << object.getPrice() << endl;
	cout << object.getName() << endl;
	cout << object.getQty() << endl;
	object.subtractQty(1);
	cout << object.getQty() << endl;*/
}

void mydatastore_test()
{
	
}
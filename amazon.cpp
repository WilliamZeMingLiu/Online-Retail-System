#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include "product.h"
#include "db_parser.h"
#include "product_parser.h"
#include "util.h"
#include "mydatastore.h"
#include "review.h"
#include "msort.h"



using namespace std;
struct ProdNameSorter {
    bool operator()(Product* p1, Product* p2) {
        return (p1->getName() < p2->getName());
    }
};
struct Date_comp {
  bool operator()(Review* lhs, Review* rhs)
  {
    return lhs->date > rhs->date;
  }
};


void displayProducts(vector<Product*>& hits);

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "Please specify a database file" << endl;
        return 1;
    }

    /****************
     * Declare your derived DataStore object here replacing
     *  DataStore type to your derived type
     ****************/
    //Changed from DataStore to MyDataStore
    MyDataStore ds;



    // Instantiate the individual section and product parsers we want
    ProductSectionParser* productSectionParser = new ProductSectionParser;
    productSectionParser->addProductParser(new ProductBookParser);
    productSectionParser->addProductParser(new ProductClothingParser);
    productSectionParser->addProductParser(new ProductMovieParser);
    UserSectionParser* userSectionParser = new UserSectionParser;
    ReviewSectionParser* reviewSectionParser = new ReviewSectionParser;
    // Instantiate the parser
    DBParser parser;
    parser.addSectionParser("products", productSectionParser);
    parser.addSectionParser("users", userSectionParser);
    parser.addSectionParser("reviews", reviewSectionParser);

    // Now parse the database to populate the DataStore
    if( parser.parse(argv[1], ds) ) {
        cerr << "Error parsing!" << endl;
        return 1;
    }

    cout << "=====================================" << endl;
    cout << "Menu: " << endl;
    cout << "  LOGIN username                     " << endl;
    cout << "  LOGOUT                             " << endl;
    cout << "  AND r/n term term ...              " << endl;
    cout << "  OR r/n term term ...               " << endl;
    cout << "  ADD search_hit_number              " << endl;
    cout << "  VIEWCART                           " << endl;
    cout << "  BUYCART                            " << endl;
    cout << "  ADDREV search_hit_number rating date review_text" << endl;
    cout << "  VIEWREV search_hit_number           " << endl;
    cout << "  QUIT new_db_filename               " << endl;
    cout << "=====================================" << endl;

    vector<Product*> hits;
    bool done = false;
    string username = "";
    while(!done) {
        cout << "\nEnter command: " << endl;
        string line;
        getline(cin,line);
        stringstream ss(line);
        string cmd;
        char sort;
        if((ss >> cmd)) {
            if(cmd == "LOGIN"){
                if (ss >> username)
                {
                    if(ds.checkUser(username))
                    {
                        username = "";
                    }
                }

            }
            else if(cmd == "LOGOUT")
            {
                username = "";
            }
            else if( cmd == "AND") {
                ss >> sort;
                if(sort != 'r' && sort != 'n')
                {
                    continue;
                }
                string term;
                vector<string> terms;
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 0, sort);
                displayProducts(hits);
            }
            else if ( cmd == "OR" ) {
                ss >> sort;
                if(sort != 'r' && sort != 'n')
                {
                    continue;
                }
                string term;
                vector<string> terms;
                while(ss >> term) {
                    term = convToLower(term);
                    terms.push_back(term);
                }
                hits = ds.search(terms, 1, sort);

                displayProducts(hits);
            }
            else if ( cmd == "QUIT") {
                string filename;
                if(ss >> filename) {
                    ofstream ofile(filename.c_str());
                    ds.dump(ofile);
                    ofile.close();
                }
                done = true;
            }
            else if ( cmd == "ADD")
            {
            	if(hits.empty())
            	{
            		cout << "Invalid request" << endl;
            	}
                else
                {
                    int unsigned hit_number;
                    ss >> hit_number;
                    if(username == "")
                    {
                        cout << "No current user" << endl;
                        continue;
                    }
                    if(hit_number > hits.size())
                    {
                        cout << "Invalid request" << endl;
                    }
                    else
                    {
                        ds.add_cart(username, hits[hit_number-1]);
                    }
                    
                    ss.clear();
                }
                
            }
            else if ( cmd == "VIEWCART")
            {
                if(username == "")
                {
                    cout << "No current user" << endl;
                    continue;
                }
                ds.view_cart(username);

            }
            else if ( cmd == "BUYCART")
            {
                if(username == "")
                {
                    cout << "No current user" << endl;
                    continue;
                }
                ds.buy_cart(username);

            }

            else if ( cmd == "ADDREV")
            {
                int unsigned hit_number;
                int rating;
                string date;
                string review_text;

                ss >> hit_number;
                if(hit_number > hits.size())
                {
                    cout << "Invalid request" << endl;
                    continue;
                }

                ss >> rating;
                if(rating > 5 || rating < 1)
                {
                    cout << "Invalid request" << endl;
                    continue;
                }

                ss >> date;
                if(date[4] != '-' || date[7] != '-')
                {
                    cout << "Invalid date format" << endl;
                    continue;
                }
                int first_month;
                int second_month;
                first_month = (int)date[5] - 48;
                second_month = (int)date[6] - 48;
                int month = first_month*10 + second_month;

                int first_day;
                int second_day;
                first_day = (int)date[8] - 48;
                second_day = (int)date[9] - 48;

                int day = first_day*10 + second_day;
                if(month > 12 || month < 1)
                {
                    cout << "Invalid date format" << endl;
                    continue;
                }

                if(month == 1 || month == 3 || month == 5 || month == 7 ||
                month == 8 || month == 10 || month == 12)
                {
                    if(day > 31 || day < 1)
                    {
                        cout << "Invalid date format" << endl;
                        continue;
                    }
                }

                else if(month == 4 || month == 6 || month == 9 || month == 11)
                {
                    if(day > 30 || day < 1)
                    {
                        cout << "Invalid date format" << endl;
                        continue;
                    }
                }
                else if(month == 2)
                {
                    if(day > 28 || day < 1)
                    {
                        cout << "Invalid date format" << endl;
                        continue;
                    }
                }

                getline(ss, review_text);
                int front_count = 0;
                int back_count = review_text.size()-1;
                while(review_text[front_count] == 32)
                {
                    front_count++;
                }
                while(review_text[front_count] == 32)
                {
                    back_count--;
                }

                for(unsigned i=0; i < review_text.size()-back_count; i++)
                {
                    review_text[i] = review_text[i+front_count];
                }
                if(username == "")
                {
                	cout << "No current user" << endl;
                	continue;
                }
                ds.addReview(hits[hit_number-1]->getName(), rating, username, date, review_text);
            }

            else if ( cmd == "VIEWREV")
            {
                int unsigned hit_number;
                ss >> hit_number;
                if(hit_number > hits.size())
                {
                    cout << "Invalid request" << endl;
                    continue;
                }
                Date_comp comp;
                mergeSort<Review*, Date_comp>(hits[hit_number-1]->review, comp);

                for(unsigned i=0; i < hits[hit_number-1]->review.size(); i++)
                {
                    cout << hits[hit_number-1]->review[i]->date << " ";
                    cout << hits[hit_number-1]->review[i]->rating << " ";
                    cout << hits[hit_number-1]->review[i]->username << " ";
                    cout << hits[hit_number-1]->review[i]->reviewText << endl;
                }
            }
            else {
                cout << "Unknown command" << endl;
            }
        }

    }
    return 0;
}

void displayProducts(vector<Product*>& hits)
{
    int resultNo = 1;
    //std::sort(hits.begin(), hits.end(), ProdNameSorter());

    for(vector<Product*>::iterator it = hits.begin(); it != hits.end(); ++it) {
        cout << "Hit " << setw(3) << resultNo << endl;
        cout << (*it)->displayString() << endl;
        cout << endl;
        resultNo++;
    }
}

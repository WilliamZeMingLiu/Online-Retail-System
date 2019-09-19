#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    std::set<std::string> keywords;
    std::string temp_string;
    rawWords += ('\0');

    for(unsigned int i=0; i < rawWords.size(); i++)
    {
        //If char is a punctuation, space, or is NULL, add the 
        //complete word into the set
        if(ispunct(rawWords[i]) || isspace(rawWords[i]) || rawWords[i] == '\0')
        {
            if(temp_string.size() >= 2)
            {
                //Converts each char to lowercase in string input
                /*for(unsigned int i=0; i < temp_string.size(); i++)
                {
                    temp_string[i] = tolower(temp_string[i]);
                }*/
                temp_string = convToLower(temp_string);
                keywords.insert(temp_string);
                temp_string.clear();
            }
            //If not, clear the temp_string for next string
            else
            {
                temp_string.clear();
            }
        }
        else
        {
            temp_string += rawWords[i];
        }
    }
    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

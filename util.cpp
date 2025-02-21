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
    set<string> words;

    string currentWord;

    stringstream spaceParser(rawWords);
    while(spaceParser >> currentWord){
        //cout << currentWord << endl;
        stringstream output;
        int start = 0;
        for(int i = 0; i < currentWord.length(); i++){
            currentWord[i] = tolower(currentWord[i]);
            //cout << currentWord[i] << endl;
            if(currentWord[i] < 'a' || currentWord[i] > 'z'){
                if(i - start > 2){
                    words.insert(currentWord.substr(start, i));
                    cout << currentWord.substr(start, i) << endl;
                    start = i + 1;
                }
            }
        }
        if(currentWord.length() - start > 2){
            words.insert(currentWord.substr(start, currentWord.length()));
            //cout << currentWord.substr(start, currentWord.length()) << endl;
        }

    }
    return words;
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

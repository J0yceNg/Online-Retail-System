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
    // set <string> keywords;

    // istringstream iss(rawWords);
    
    // do { //iterate istringstrem
    //     string substr = "";
    //     string substr2 = "";
    //     iss >> substr; //removes whitespace

    //     for(char s: substr){ //split at punctuation
    //         if(ispunct(s) != 0){
    //             int loc = substr.find(s);
    //             if(substr.substr(loc + 1).length() >= 2){ //substring after
    //                 substr = substr.substr(loc + 1);
    //             }
    //             if(substr.substr(0, loc).length() >= 2){ //substring before
    //                 substr2 = substr.substr(0, loc);
    //             }
    //             if(substr != substr.substr(loc + 1) && substr2 != substr.substr(0, loc)){ //if neither greater than 2
    //                 continue;
    //             }
    //         }
    //     }
    //     convToLower(substr); //convert to lower case
    //     convToLower(substr2);

    //     if(substr != ""){
    //         keywords.insert(substr); //populate set
    //     }
    //     if(substr2 != ""){
    //         keywords.insert(substr2); //populate set
    //     }

    // } while (iss);

    // return keywords;

    set<string> keywords;
    string substr;
    string token;
    istringstream iss(rawWords);

    while (iss >> substr) {
      token = "";
      for(char& s : substr){
        if(ispunct(s)){
          if(token.length() >= 2){ //check of token before punct
            token = convToLower(token);
            keywords.insert(token); //adding valid token
          }
          token = "";
        }
        else{
          token += s;
        }
      }
      if(token.length() >= 2){
        token = convToLower(token);
        keywords.insert(token);
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

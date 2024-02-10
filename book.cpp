#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, 
        const std::string isbn, const std::string author):
    Product(category, name, price, qty),
    isbn_(isbn),
    author_(author)
{

}

Book::~Book()
{

}

/**
 * Returns the appropriate keywords that this product should be associated with
 */
std::set<std::string> Book::keywords() const{
    set<string> keys;
    set<string> authorkeys = parseStringToWords(author_);
        keys.insert(authorkeys.begin(), authorkeys.end());
    set<string> titlekeys = parseStringToWords(name_);
        keys.insert(titlekeys.begin(), titlekeys.end());
    keys.insert(isbn_);
    return keys;
}

/**
 * Returns a string to display the product info for hits of the search
 */
std::string Book::displayString() const{
    std::ostringstream info;
    info << name_ << "\n" << "Author: " << author_ << " ISBN: " << isbn_ << "\n"
    << std::fixed << std::setprecision(2) << price_ << " " << qty_ << " left.\n";
    return info.str();
}

/**
 * Outputs the product info in the database format
 */
void Book::dump(std::ostream& os) const{
    Product::dump(os);
    os << isbn_ << "\n" << author_ << endl;

}
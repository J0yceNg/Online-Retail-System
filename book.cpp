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
    set<string> keys = parseStringToWords(author_);
    keys.insert(parseStringToWords(name_).begin(), parseStringToWords(name_).end());
    keys.insert(isbn_);
    return keys;
}

/**
 * Returns a string to display the product info for hits of the search
 */
std::string Book::displayString() const{
    string info = name_ + "\nAuthor: " + author_ + " ISBN: " + isbn_
    + "\n" + to_string(price_) + " " + to_string(qty_) + "left.\n";
    return info;
}

/**
 * Outputs the product info in the database format
 */
void Book::dump(std::ostream& os) const{
    Product::dump(os);
    os << isbn_ << "\n" << author_ << endl;

}
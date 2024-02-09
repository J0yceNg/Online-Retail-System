#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, 
        const std::string genre, const std::string rating):
    Product(category, name, price, qty),
    genre_(genre),
    rating_(rating)
{

}

Movie::~Movie()
{

}

/**
 * Returns the appropriate keywords that this product should be associated with
 */
std::set<std::string> Movie::keywords() const{
    set<string> keys;
    keys.insert(parseStringToWords(name_).begin(), parseStringToWords(name_).end());
    keys.insert(genre_);
    return keys;
}

/**
 * Returns a string to display the product info for hits of the search
 */
std::string Movie::displayString() const{
    string info = name_ + "\nGenre: " + genre_ + " Rating: " + rating_
    + "\n" + to_string(price_) + " " + to_string(qty_) + "left.\n";
    return info;
}

/**
 * Outputs the product info in the database format
 */
void Movie::dump(std::ostream& os) const{
    Product::dump(os);
    os << genre_ << "\n" << rating_ << endl;

}
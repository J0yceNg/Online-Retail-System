#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, 
        const std::string size, const std::string brand):
    Product(category, name, price, qty),
    size_(size),
    brand_(brand)
{

}

Clothing::~Clothing()
{

}

/**
 * Returns the appropriate keywords that this product should be associated with
 */
std::set<std::string> Clothing::keywords() const{
    set<string> keys = parseStringToWords(brand_);
    keys.insert(parseStringToWords(name_).begin(), parseStringToWords(name_).end());
    return keys;
}

/**
 * Returns a string to display the product info for hits of the search
 */
std::string Clothing::displayString() const{
    string info = name_ + "\nSize: " + size_ + " Brand: " + brand_
    + "\n" + to_string(price_) + " " + to_string(qty_) + "left.\n";
    return info;
}

/**
 * Outputs the product info in the database format
 */
void Clothing::dump(std::ostream& os) const{
    Product::dump(os);
    os << size_ << "\n" << brand_ << endl;

}
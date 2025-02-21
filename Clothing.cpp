#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Clothing.h"
#include "util.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) : Product(category, name, price, qty){
    size_ = size;
    brand_ = brand;
}

std::set<std::string> Clothing::keywords() const{
    std::set<std::string> name = parseStringToWords(name_);
    std::set<std::string> brand = parseStringToWords(brand_);
    std::set<std::string> output = setUnion(name, brand);
    return output;
}

std::string Clothing::displayString() const{
    std::stringstream out;
    out << name_ << std::endl;
    out << "Size: " << size_ << " Brand: " << brand_ << std::endl;
    out << price_ << " " << qty_ << " left.";
    return out.str();
}

void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << std::endl;
}

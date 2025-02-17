#include <algorithm>
#include <sstream>
#include <iomanip>
#include "book.h"
#include "util.h"

std::set<std::string> Book::keywords() const{
    std::set<std::string> name = parseStringToWords(name_);
    std::set<std::string> author = parseStringToWords(author_);
    std::set<std::string> output = setIntersection(name, author);
    output.insert(ISBN_);
    
    return output;
}

std::string Book::displayString() const{
    std::stringstream out;
    out << name_ << std::endl;
    out << "Author: " << author_ << " ISBN: " << ISBN_ << std::endl;
    out << price_ << " " << qty_ << " left.";
    return out.str();

}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << ISBN_ << "\n" << author_ << std::endl;
}

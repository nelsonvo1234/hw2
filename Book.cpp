#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Book.h"
#include "util.h"

Book::Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author) : Product(category, name, price, qty){
    ISBN_ = ISBN;
    author_ = author;
}

std::set<std::string> Book::keywords() const{
    std::set<std::string> name = parseStringToWords(name_);
    std::set<std::string> author = parseStringToWords(author_);
    std::set<std::string> output = setUnion(name, author);
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

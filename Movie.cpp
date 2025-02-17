#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Movie.h"
#include "util.h"

std::set<std::string> Movie::keywords() const{
    std::set<std::string> name = parseStringToWords(name_);
    std::set<std::string> genre = parseStringToWords(genre_);
    std::set<std::string> output = setIntersection(name, genre);    
    return output;
}

std::string Movie::displayString() const{
    std::stringstream out;
    out << name_ << std::endl;
    out << "Genre: " << genre_ << " Raing: " << rating_ << std::endl;
    out << price_ << " " << qty_ << " left.";
    return out.str();
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << std::endl;
}

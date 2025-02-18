#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : public Product{
    public:
        Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author);
        virtual std::set<std::string> keywords() const;
        virtual std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        std::string ISBN_;
        std::string author_;
};

#endif
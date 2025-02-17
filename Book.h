#ifndef BOOK_H
#define BOOK_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Book : Product{
    public:
        virtual std::set<std::string> keywords() const;
        virtual std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        std::string ISBN_;
        std::string author_;
};

#endif
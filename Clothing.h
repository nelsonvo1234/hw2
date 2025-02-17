#ifndef CLOTHING_H
#define CLOTHING_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Clothing : Product{
    public:
        virtual std::set<std::string> keywords() const;
        virtual std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        std::string size_;
        std::string brand_;
};

#endif
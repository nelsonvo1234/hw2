#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include "product.h"

class Movie : Product{
    public:
        virtual std::set<std::string> keywords() const;
        virtual std::string displayString() const;
        void dump(std::ostream& os) const;
    protected:
        std::string genre_;
        std::string rating_;
};

#endif
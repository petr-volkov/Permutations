//
// Created by petr_v on 25/11/2015.
//

#ifndef PERMUTATIONS_BEDENTRY_H
#define PERMUTATIONS_BEDENTRY_H

#include <string>
#include <vector>
#include <iostream>

class BedEntry {
public:
    BedEntry(std::string, long, long);
    long intersect(BedEntry entry);
    long getStart() const;
    long getEnd() const;
    std::string getChr() const;

    void setStart(long);
    void setEnd(long);
    void setChr(std::string);

    friend std::ostream& operator<< (std::ostream& out, BedEntry &entry);
    friend bool operator<(const BedEntry &first, const BedEntry &second);
    friend bool operator>(const BedEntry &first, const BedEntry &second);
    friend bool operator== (const BedEntry &first, const BedEntry &second);
    friend bool operator!= (const BedEntry &first, const BedEntry &second);

private:
    std::string chr;
    long start;
    long end;
};




#endif //PERMUTATIONS_BEDENTRY_H

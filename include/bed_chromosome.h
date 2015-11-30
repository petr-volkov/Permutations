//
// Created by petr_v on 26/11/2015.
//

#ifndef PERMUTATIONS_BED_CHROMOSOME_H
#define PERMUTATIONS_BED_CHROMOSOME_H

#include "bed_entry.h"
#include <tuple>
#include <set>

typedef std::vector<std::tuple<BedEntry, BedEntry>> bedIntersect;

class BedChromosome {
public:
    BedChromosome(std::string chr);
    void sort(); //it's up to a user of a class to sort when needed
    void push_back(BedEntry &entry);
    unsigned long size() const;
    BedEntry& operator[] (int i);
    std::vector<BedEntry> const &getEntries() const;

    bedIntersect intersect(BedEntry &);
    void intersect(BedEntry &, bedIntersect &result);
    void intersect(BedChromosome &, bedIntersect &);
    void changeChromosome(std::string chr);
private:
    std::string chr;
    std::vector<BedEntry> entries; //maybe make private
};

bool endCompare(const BedEntry &first, const BedEntry &second);
bool startCompare(const BedEntry &first, const BedEntry &second);
#endif //PERMUTATIONS_BED_CHROMOSOME_H

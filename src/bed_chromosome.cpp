//
// Created by petr_v on 26/11/2015.
//

#include <stdexcept>
#include <algorithm>
#include <iomanip>
#include "bed_chromosome.h"
#include "genome_info.h"



BedChromosome::BedChromosome(std::string chr) : chr(chr) {
    if(GenomeInfo::chrInfo.find(chr) == GenomeInfo::chrInfo.end()) {
        throw std::invalid_argument("Wrong chromosome!");
    }
    entries.reserve(10000);
}

void BedChromosome::push_back(BedEntry &entry) {
    if(entry.getChr() != chr) {
        throw std::invalid_argument("Attempt to push wrong chromosome");
    }
    entries.push_back(entry);
}

unsigned long BedChromosome::size() const {
    return entries.size();
}

void BedChromosome::sort() {
    std::stable_sort(entries.begin(), entries.end());
}

BedEntry &BedChromosome::operator[](int i) {
    return entries[i];
}

std::vector<BedEntry> const &BedChromosome::getEntries() const {
    return entries;
}

bool startCompare(const BedEntry &first, const BedEntry &second) {
    return first.getStart() < second.getEnd();
}

bool endCompare(const BedEntry &first, const BedEntry &second) {
    return first.getEnd() < second.getStart();
}

//this->entries should be sorted by this point.
//if not, it is a fault of a class user
bedIntersect BedChromosome::intersect(BedEntry &queryEntry) {
    bedIntersect res;

    //find index of the first element with start larger then entry.end() (for simplisity now query.start() - shouldn't be a big difference)
    std::vector<BedEntry>::iterator upper = std::upper_bound(entries.begin(), entries.end(), queryEntry, endCompare);

    //find index of the last element with end smaller then entry.start()
    std::vector<BedEntry>::iterator lower = std::lower_bound(entries.begin(), upper, queryEntry, endCompare);

    //returns a tuple of type <thisobject.BedEntry, anotherBedEntry>
    for( std::vector<BedEntry>::iterator it = lower; it != upper; it++) {
        if(it->intersect(queryEntry)) {
            res.push_back(std::make_tuple(*it, queryEntry));
        }
    }
    return res;
}

void BedChromosome::intersect(BedEntry &queryEntry, bedIntersect &result) {
    //find index of the first element with start larger then entry.end() (for simplisity now query.start() - shouldn't be a big difference)
    std::vector<BedEntry>::iterator upper = std::upper_bound(entries.begin(), entries.end(), queryEntry, endCompare);

    //find index of the last element with end smaller then entry.start()
    std::vector<BedEntry>::iterator lower = std::lower_bound(entries.begin(), upper, queryEntry, endCompare);

    //returns a tuple of type <thisobject.BedEntry, anotherBedEntry>
    for( std::vector<BedEntry>::iterator it = lower; it != upper; it++) {
        if(it->intersect(queryEntry)) {
            result.push_back(std::make_tuple(*it, queryEntry));
        }
    }
}

//bedIntersect BedChromosome::intersect(BedChromosome &chromosome) {
//    // this is a major function that will return intersect between 2 chromosomes
//    bedIntersect allIntersects;
//    allIntersects.reserve(chr.size());
//    for( BedEntry &entry : chromosome.entries) {
//        intersect(entry, allIntersects);
//    }
//    return allIntersects;
//}

void BedChromosome::intersect(BedChromosome &chromosome, bedIntersect &result) {
    for( BedEntry &entry : chromosome.entries) {
        intersect(entry, result);
    }
}

void BedChromosome::changeChromosome(std::string newChr) {
    chr = newChr;
    for (auto &entry : entries) {
        entry.setChr(newChr);
    }
}
//
// Created by petr_v on 25/11/2015.
//

#ifndef PERMUTATIONS_BED_H
#define PERMUTATIONS_BED_H

#include "bed_entry.h"
#include "bed_chromosome.h"
#include <unordered_map>
#include <map>

typedef std::unordered_map<std::string, BedChromosome> chromosomeMap;
typedef std::vector<std::tuple<BedEntry, BedEntry>> bedIntersect;


class Bed {
public:
    Bed();
    void add_entry(BedEntry &);
    chromosomeMap const& getChromosomes() const;
    long int size() const;
    void sort();
    bedIntersect intersect(Bed &);
    void writeIntersect(bedIntersect &intersect, std::string outputFilePath);
    void permute();
    void writeBed(std::string outputFilePath);
private:
    chromosomeMap chromosomes;
};

#endif //PERMUTATIONS_BED_H

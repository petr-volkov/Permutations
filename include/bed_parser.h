//
// Created by petr_v on 25/11/2015.
//

#ifndef PERMUTATIONS_BEDPARSER_H
#define PERMUTATIONS_BEDPARSER_H

#include <vector>
#include "bed_entry.h"
#include "bed.h"

class BedParser {
public:
    BedParser(std::string, int = 1);
    std::string getFilePath();
    bool parse();
    const unsigned int defaultSize = 10000;
    const Bed& getParsedBed() const;
private:
    std::string filePath;
    Bed parsed;
    int skip;
};

bool fileExists(const std::string &);


#endif //PERMUTATIONS_BEDPARSER_H

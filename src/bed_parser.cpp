//
// Created by petr_v on 25/11/2015.
//

#include <string>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "bed_parser.h"
#include "limits.h"
#include "bed_entry.h"
#include "split.h"
#include "str2int.h"

BedParser::BedParser(std::string filePath, int skip) : filePath(filePath), skip(skip) {
    if (!fileExists(filePath)) {
        throw std::exception();
    }

    if(!parse()) {
        throw std::exception();
    }
}

std::string BedParser::getFilePath() {
    return this -> filePath;
}

bool BedParser::parse() {
    std::ifstream infile(filePath);
    std::string line;
    int i = 0;
    while(std::getline(infile, line)) {
        if(i < skip) {
            i++;
            continue;
        }

        std::vector<std::string> splitted = split(line, '\t');
        //check that we have at least 3 elements
        if(splitted.size() < 3) {
            return false;
        }

        std::string chr = splitted[0];
        long int start;
        long int end;
        if( str2int(start, splitted[1].c_str()) != STR2INT_SUCCESS) {
            return false;
        }
        if( str2int(end, splitted[2].c_str()) != STR2INT_SUCCESS) {
            return false;
        }
        BedEntry entry(chr, start+1, end);
        parsed.add_entry(entry);
    }
    return true;
}


//////////////////////////////////////////////
// Functions to help with file manipulation //
//////////////////////////////////////////////

bool fileExists(const std::string &filePath) {
    std::ifstream infile(filePath);
    return infile.good();
}

const Bed &BedParser::getParsedBed() const {
    return parsed;
}

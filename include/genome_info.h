//
// Created by petr_v on 26/11/2015.
//

#ifndef PERMUTATIONS_GENOME_INFO_H
#define PERMUTATIONS_GENOME_INFO_H

#include <string>
#include <vector>
#include <map>
#include <unordered_map>

class GenomeInfo {
public:
    //static const std::vector<std::string> acceptedChrList;
    static const std::unordered_map<std::string, long int> chrInfo;
};


#endif //PERMUTATIONS_GENOME_INFO_H

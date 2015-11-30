//
// Created by petr_v on 30/11/2015.
//

#ifndef PERMUTATIONS_BED_RANDOMIZER_H
#define PERMUTATIONS_BED_RANDOMIZER_H

#include "bed.h"
#include <random>

class BedRandomizer {
public:
    BedRandomizer();
    void randomize(const Bed &bed, Bed &newbed);
    void generateChrProbabilities(const std::vector<double> &, std::vector<double> &);
    void calculateCummsum(const std::vector<double> &, std::vector<double> &);
    int identifyProbabilityInterval(const std::vector<double> &, double);
    void randomChromosomeName(const std::vector<std::string> &, const std::vector<double> &, std::string &);

private:
    std::vector<std::string> chrNames;
    std::vector<double> counts;
    std::vector<double> probabilities;
    std::vector<double> cummsum;
    std::random_device randomDevice;
    std::mt19937 generator;
    std::uniform_real_distribution<> zeroToOneDistribution;
};


#endif //PERMUTATIONS_BED_RANDOMIZER_H

//
// Created by petr_v on 30/11/2015.
//

#include "bed_randomizer.h"
#include "genome_info.h"
#include "algorithm"
#include "bed_entry.h"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <random>

BedRandomizer::BedRandomizer() : generator(randomDevice()), zeroToOneDistribution(0, 1) {

    for(auto info : GenomeInfo::chrInfo) {
        chrNames.push_back(info.first);
        counts.push_back(info.second);
    }

    generateChrProbabilities(counts, probabilities);
    calculateCummsum(probabilities, cummsum);
}

void BedRandomizer::randomize(const Bed &bed, Bed &newbed) {
    GenomeInfo::chrInfo.at("chr1");
    for(const auto &chr : bed.getChromosomes()) {
        for(const auto &entry : chr.second.getEntries()) {
            std::string newChrName;
            randomChromosomeName(chrNames, cummsum, newChrName);
            long chrLength = GenomeInfo::chrInfo.at(newChrName); // <---- this thing is very slow, think how to refactor.
            long entryLength = entry.getEnd() - entry.getStart();
            std::uniform_int_distribution<> chrDistribution(1, chrLength - entryLength);
            int randomStart = chrDistribution(generator);
            int randomEnd = randomStart + entryLength;
            BedEntry newEntry(newChrName, randomStart, randomEnd);
            newbed.add_entry(newEntry);
        }
    }
}

void BedRandomizer::randomChromosomeName(const std::vector<std::string> &chrNames, const std::vector<double> &cummsum,
                                         std::string &result) {
    double r = zeroToOneDistribution(generator);
    int i = identifyProbabilityInterval(cummsum, r);
    result = chrNames[i];
}

void BedRandomizer::generateChrProbabilities(const std::vector<double> &counts, std::vector<double> &probabilities) {
    double sum = 0;
    for(double count : counts) {
        sum += count;
    }

    for(double count : counts) {
        probabilities.push_back(count / sum);
    }
}

void BedRandomizer::calculateCummsum(const std::vector<double> &probabilities, std::vector<double> &cummsum) {
    double sum = 0;
    for(double prob : probabilities) {
        sum += prob;
        cummsum.push_back(sum);
    }
}

int BedRandomizer::identifyProbabilityInterval(const std::vector<double> &cummsum, double d) {
    auto it = std::lower_bound(cummsum.begin(), cummsum.end(), d);
    return it - cummsum.begin();
}

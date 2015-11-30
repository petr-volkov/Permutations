//
// Created by petr_v on 25/11/2015.
//

#include <iostream>
#include <algorithm>
#include "genome_info.h"
#include "bed.h"
#include "bed_chromosome.h"

Bed::Bed() {
    for(auto chr : GenomeInfo::chrInfo) {
        BedChromosome chromosome(chr.first);
        chromosomes.insert(std::make_pair(chr.first, chromosome));
    }
}

chromosomeMap const &Bed::getChromosomes() const {
    return chromosomes;
}

void Bed::add_entry(BedEntry &entry) {
    chromosomes.at(entry.getChr()).push_back(entry);
}

long int Bed::size() const {
    long size = 0;
    for(auto const &kv : chromosomes) {
        size += kv.second.size();
    }
    return size;
}

void Bed::sort() {
    for(auto &kv : chromosomes) {
        kv.second.sort();
    }
}

bedIntersect Bed::intersect(Bed &secondBed) {
    bedIntersect res = bedIntersect();
    res.reserve(chromosomes.size());

    for (auto &chr : chromosomes) {
        std::string chrName = chr.first;
        BedChromosome secondChromosome = secondBed.getChromosomes().at(chrName);
        chr.second.intersect(secondChromosome, res);
    }
    return res;
}

void Bed::printIntersect(bedIntersect &intersect) {
    for(auto &tuple : intersect) {
        std::cout << std::get<0>(tuple) << '\t' <<std::get<1>(tuple) << std::endl;
    }
}

void Bed::permute() {
    GenomeInfo genomeInfo;

    //shuffle chromosome
    std::vector<std::string> nonshuffledChromosomes;
    std::vector<std::string> reshuffledChromosomes;
    for(auto chr : GenomeInfo::chrInfo) {
        nonshuffledChromosomes.push_back(chr.first);
        reshuffledChromosomes.push_back(chr.first);
    }
    std::random_shuffle(reshuffledChromosomes.begin(), reshuffledChromosomes.end());

    for(int i = 0; i < reshuffledChromosomes.size(); i++) {
        std::string oldChr = nonshuffledChromosomes[i];
        std::string newChr = reshuffledChromosomes[i];

        chromosomes.at(oldChr).changeChromosome(newChr);
        chromosomes.at(newChr).changeChromosome(oldChr);

        std::swap(chromosomes.at(oldChr), chromosomes.at(newChr));
    }
}

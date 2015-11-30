#include <iostream>
#include <stdio.h>
#include <random>
#include <genome_info.h>
#include "bed_randomizer.h"
#include "bed_parser.h"
#include "bed_entry.h"
#include "bed.h"


using namespace std;

int main() {
    std::srand(static_cast <unsigned> (time(0)));
    clock_t tStart = clock();

    BedParser parser1("../test/test_input/FOXA2_1_nohead.bed", 0);
    BedParser parser2("../test/test_input/FOXA2_2_nohead.bed", 0);
    Bed bed1 = parser1.getParsedBed();
    Bed bed2 = parser2.getParsedBed();
    bed1.sort();
    bed2.sort();
    bedIntersect intersect = bed1.intersect(bed2);

    printf("Time taken to intersect 1 file: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);

    tStart = clock();
    BedRandomizer randomizer;
    std::random_device rd;
    std::mt19937 gen(rd());

    for(long i = 0; i <= 1000; i++) {
        Bed newbed;
        randomizer.randomize(bed2, newbed);
    }
    printf("Time taken to permute 1 bed 100 times: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    return 0;
}
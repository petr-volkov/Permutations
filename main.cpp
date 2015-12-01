#include <iostream>
#include <stdio.h>
#include <random>
#include <genome_info.h>
#include "bed_randomizer.h"
#include "bed_parser.h"
#include <chrono>
#include "bed_entry.h"
#include "bed.h"


using namespace std;

int main() {
    std::srand(static_cast <unsigned> (time(0)));


    BedParser parser1("../test/test_input/FOXA2_1_nohead.bed", 0);
    BedParser parser2("../test/test_input/FOXA2_2_nohead.bed", 0);
    Bed bed1 = parser1.getParsedBed();
    Bed bed2 = parser2.getParsedBed();
    bed1.sort();
    bed2.sort();
    bedIntersect intersect = bed1.intersect(bed2);


    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    int n = 1000;
    //std::vector<int>

    #pragma omp parallel for
    for(long i = 0; i < n; i++) {
        BedRandomizer randomizer;
        Bed newbed;
        randomizer.randomize(bed2, newbed);
    }

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Time taken to run 1000 iterations: " << duration / 1000. << " seconds" << std::endl;
    return 0;
}
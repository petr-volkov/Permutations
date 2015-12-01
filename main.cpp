#include <iostream>
#include <random>
#include <genome_info.h>
#include "bed_randomizer.h"
#include "bed_parser.h"
#include <chrono>



using namespace std;

int main(int argc, char **argv) {

    std::string file1(argv[1]);
    std::string file2(argv[2]);

    std::cout << "File 1: " << file1 << std::endl;
    std::cout << "File 2: " << file2 << std::endl;


    BedParser parser1(file1, 0);
    BedParser parser2(file2, 0);
    Bed bed1 = parser1.getParsedBed();
    Bed bed2 = parser2.getParsedBed();
    bed1.sort();
    bed2.sort();
    bedIntersect intersect = bed1.intersect(bed2);
    std::cout << "Length of original intersect is " << intersect.size() << std::endl;


    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    int n = 100;
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
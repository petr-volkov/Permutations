#include <iostream>
#include <fstream>
#include <random>
#include <genome_info.h>
#include <chrono>
#include "bed_randomizer.h"
#include "bed_parser.h"
#include "str2int.h"

using namespace std;

int main(int argc, char **argv) {
    std::string file1(argv[1]);
    std::string file2(argv[2]);
    std::string outputFilePath(argv[3]);
    long n;
    str2int(n, argv[4]);

    std::cout << "File 1: " << file1 << std::endl;
    std::cout << "File 2: " << file2 << std::endl;

    BedParser parser1(file1, 0);
    BedParser parser2(file2, 0);
    Bed bed1 = parser1.getParsedBed();
    Bed bed2 = parser2.getParsedBed();

    std::cout << "Parsed first file: " << bed1.size() << " entries\n";
    std::cout << "Parsed second file: " << bed2.size() << " entries\n";

    bed1.sort();
    bed2.sort();
    bedIntersect intersectToTest = bed1.intersect(bed2);
    std::cout << "Length of original intersect is " << intersectToTest.size() << std::endl;

    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();

    unsigned long *result;
    result = new unsigned long [n];

    #pragma omp parallel for
    for(long i = 0; i < n; i++) {
        BedRandomizer randomizer;
        Bed newbed;
        randomizer.randomize(bed2, newbed);
        newbed.sort();
        bedIntersect intersect = bed1.intersect(newbed);

        if(intersect.size() < 0) {
            std::cout << "Some weird stuff!" << std::endl;
        }
        result[i] = intersect.size();
    }

    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
    std::cout << "Time taken to run 1000 iterations: " << duration / 1000. << " seconds" << std::endl;

    std::ofstream outputFile;
    outputFile.open(outputFilePath);

    for(int i = 0; i < n; i++) {
        outputFile << result[i] << std::endl;
    }
    outputFile.close();
    delete[] result;
    return 0;
}
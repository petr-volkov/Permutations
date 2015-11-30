//
// Created by petr_v on 26/11/2015.
//

#include "genome_info.h"
#include <iostream>
#include <fstream>

//const std::vector<std::string> GenomeInfo::acceptedChrList {
//        "chr1",
//        "chr2",
//        "chr3",
//        "chr4",
//        "chr5",
//        "chr6",
//        "chr7",
//        "chr8",
//        "chr9",
//        "chr10",
//        "chr11",
//        "chr12",
//        "chr13",
//        "chr14",
//        "chr15",
//        "chr16",
//        "chr17",
//        "chr18",
//        "chr19",
//        "chr20",
//        "chr21",
//        "chr22",
//        "chrX",
//        "chrY"
//};

const std::unordered_map<std::string, long int> GenomeInfo::chrInfo {
        {"chr1", 249698942},
        {"chr2", 242508799},
        {"chr3", 198450956},
        {"chr4", 190424264},
        {"chr5", 181630948},
        {"chr6", 170805979},
        {"chr7", 159345973},
        {"chr8", 145138636},
        {"chr9", 138688728},
        {"chr10", 133797422},
        {"chr11", 135186938},
        {"chr12", 133275309},
        {"chr13", 114364328},
        {"chr14", 108136338},
        {"chr15", 102439437},
        {"chr16", 92211104},
        {"chr17", 83836422},
        {"chr18", 80373285},
        {"chr19", 58617616},
        {"chr20", 64444167},
        {"chr21", 46709983},
        {"chr22", 51857516},
        {"chrX", 156040895},
        {"chrY", 57264655},
        {"chrUn", 4485509}
};
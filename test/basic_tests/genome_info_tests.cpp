//
// Created by petr_v on 30/11/2015.
//

#include "gtest/gtest.h"
#include "genome_info.h"
TEST(TestGenomeInfo, ConstructorParsesCorrectlyIfRightFormat) {
    GenomeInfo::chrInfo.at("chr1") == 249698942;
    GenomeInfo::chrInfo.at("chrY") == 249698942;
}

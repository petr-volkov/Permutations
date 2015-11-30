//
// Created by petr_v on 30/11/2015.
//

#include "gtest/gtest.h"
#include "bed_randomizer.h"
#include "bed_parser.h"

TEST(TestBedRandomizer, CorrectlyGeneratesFrequencies) {
    std::vector<double> counts = {1., 2., 3., 4., 5.};
    std::vector<double> target = {1./15, 2./15, 3./15, 4./15, 5./15};
    std::vector<double> result;
    BedRandomizer randomizer;
    randomizer.generateChrProbabilities(counts, result);
    ASSERT_EQ(target, result);
}

TEST(TestBedRandomizer, CorrectlyGeneratesCummSum) {
    std::vector<double> probabilities = {1./15, 2./15, 3./15, 4./15, 5./15};
    std::vector<double> target = {1./15,
                                  1./15 + 2./15,
                                  1./15 + 2./15 + 3./15,
                                  1./15 + 2./15 + 3./15 + 4./15,
                                  1./15 + 2./15 + 3./15 + 4./15 + 5./15};
    std::vector<double> result;
    BedRandomizer randomizer;
    randomizer.calculateCummsum(probabilities, result);
    ASSERT_EQ(target, result);
}

TEST(TestBedRandomizer, CorrectlyIdentifiesProbabilityInterval) {
    std::vector<double> cummsum = {1./15,
                                   1./15 + 2./15,
                                   1./15 + 2./15 + 3./15,
                                   1./15 + 2./15 + 3./15 + 4./15,
                                   1./15 + 2./15 + 3./15 + 4./15 + 5./15};
    double first_search = 0.;
    double second_search = 1/15;
    double third_search = 0.41;
    double forth_search = 1.;

    BedRandomizer randomizer;
    ASSERT_EQ(0, randomizer.identifyProbabilityInterval(cummsum, first_search));
    ASSERT_EQ(0, randomizer.identifyProbabilityInterval(cummsum, second_search));
    ASSERT_EQ(3, randomizer.identifyProbabilityInterval(cummsum, third_search));
    ASSERT_EQ(4, randomizer.identifyProbabilityInterval(cummsum, forth_search));
}
TEST(TestBedRandomizer, RandomizeWontThrow) {
    BedParser parser("../test/test_input/FOXA2_1_nohead.bed", 0);
    Bed bed = parser.getParsedBed();
    Bed newbed;
    BedRandomizer randomizer;
    ASSERT_NO_THROW(randomizer.randomize(bed, newbed));
}
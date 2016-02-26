//
// Created by petr_v on 26/11/2015.
//

#include <bed_parser.h>
#include "gtest/gtest.h"

TEST(BedChromosomeTest, RaiseIfAddedWrongChromosome) {
    BedChromosome bedChr("chr1");
    BedEntry entry("chr2", 100, 200);
    ASSERT_ANY_THROW(bedChr.push_back(entry));
}
TEST(BedChromosomeTest, NoRaiseifAddedCorrectChromosome) {
    BedChromosome bedChr("chr1");
    BedEntry entry("chr1", 100, 200);
    ASSERT_NO_THROW(bedChr.push_back(entry));
}
TEST(BedChromosomeTest, AddedCorrectly) {
    BedChromosome bedChr("chr1");
    BedEntry entry("chr1", 100, 200);
    long length = bedChr.size();
    bedChr.push_back(entry);
    ASSERT_EQ(length + 1, bedChr.size());
}

TEST(BedChromosomeTest, ConstructorThrowsIfWrongChrosomome) {
    ASSERT_ANY_THROW(BedChromosome test("chr123"));
}
TEST(BedChromosomeTest, OverloadedBracketOperator) {
    BedEntry entry("chr1", 100, 200);
    BedChromosome chromosome("chr1");
    chromosome.push_back(entry);
    ASSERT_TRUE(chromosome[0] == entry);
}
TEST(BedChromosomeTest, SortsCorrectly) {
    BedEntry entry1("chr1", 300, 301);
    BedEntry entry2("chr1", 200, 300);
    BedEntry entry3("chr1", 100, 400);
    BedChromosome chromosome("chr1");
    chromosome.push_back(entry1);
    chromosome.push_back(entry2);
    chromosome.push_back(entry3);
    chromosome.sort();

    ASSERT_TRUE(chromosome[0] < chromosome[1]);
    ASSERT_TRUE(chromosome[1] < chromosome[2]);
}
TEST(BedChromosomeTest, SortingIsStable) {
    BedEntry entry1("chr1", 300, 301);
    BedEntry entry2("chr1", 200, 400);
    BedEntry entry3("chr1", 200, 300);
    BedChromosome chromosome("chr1");
    chromosome.push_back(entry1);
    chromosome.push_back(entry2);
    chromosome.push_back(entry3);
    chromosome.sort();

    ASSERT_TRUE(chromosome[0] == entry2);
    ASSERT_TRUE(chromosome[1] == entry3);
}
TEST(BedChromosomeTest, IntersectReturnsRightAmount) {
    BedParser parser1("../test/test_input/FOXA2_1_chr1.bed", 0);
    BedParser parser2("../test/test_input/FOXA2_2_chr1.bed", 0);
    Bed bed1 = parser1.getParsedBed();
    Bed bed2 = parser2.getParsedBed();
    BedChromosome firstChr1 = bed1.getChromosomes().at("chr1");
    BedChromosome secondChr1 = bed2.getChromosomes().at("chr1");
    bedIntersect result1;
    bedIntersect result2;

    secondChr1.intersect(firstChr1, result2);
    firstChr1.intersect(secondChr1, result1);


    ASSERT_EQ(1729, result1.size());
    ASSERT_EQ(1729, result2.size());
}
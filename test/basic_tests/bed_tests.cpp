//
// Created by petr_v on 26/11/2015.
//


#include "gtest/gtest.h"
#include "bed.h"
#include "bed_parser.h"
#include "genome_info.h"
#include <algorithm>


TEST(TestBed, ConstructorCreatesAllChromosomes) {
    Bed bed;
    for (auto info : GenomeInfo::chrInfo) {
        std::string chr = info.first;
        ASSERT_TRUE(bed.getChromosomes().find(chr) != bed.getChromosomes().end());
    }
}

TEST(TestBed, InsertsEntry) {
    BedEntry entry("chr14", 10000, 50000);
    Bed bed;
    bed.add_entry(entry);
    ASSERT_EQ(bed.getChromosomes().at("chr14").size(), 1);
}

TEST(TestBed, CalcuatesTotalSizeCorrectly) {
    BedEntry entry1("chr1", 10000, 50000);
    BedEntry entry2("chr2", 10000, 50000);
    BedEntry entry3("chr3", 10000, 50000);
    BedEntry entry4("chr4", 10000, 50000);
    BedEntry entry5("chr5", 10000, 50000);

    Bed bed;

    bed.add_entry(entry1);
    bed.add_entry(entry2);
    bed.add_entry(entry3);
    bed.add_entry(entry4);
    bed.add_entry(entry5);

    ASSERT_EQ(bed.size(), 5);
}
TEST(TestBed, SortsCorrectly) {
    std::string correct_file = "../test/test_input/FOXA2_1_unsorted.bed";
    BedParser parser(correct_file);
    Bed bed = parser.getParsedBed();
    bed.sort();
    BedChromosome chr1 = bed.getChromosomes().at("chr1");
    BedChromosome chrX = bed.getChromosomes().at("chrX");

    ASSERT_TRUE(std::is_sorted(chr1.getEntries().begin(), chr1.getEntries().end()));
    ASSERT_TRUE(std::is_sorted(chrX.getEntries().begin(), chrX.getEntries().end()));
}
TEST(TestBed, IntersectReturnsRightAmount) {
    std::string firstFile = "../test/test_input/FOXA2_1_unsorted.bed";
    std::string secondFile = "../test/test_input/FOXA2_1_unsorted.bed";

    BedParser parser1("../test/test_input/FOXA2_1_nohead.bed", 0);
    BedParser parser2("../test/test_input/FOXA2_2_nohead.bed", 0);
    Bed bed1 = parser1.getParsedBed();
    Bed bed2 = parser2.getParsedBed();

    // bamtools gives here 19506. We give here 19507 because
    // there is an intersect that looks like this: "chr5  51822394  51824083 chr5  51824083  51824867"
    // (it contains only 1 base pair)
    ASSERT_EQ(19507, bed1.intersect(bed2).size());
    ASSERT_EQ(19507, bed2.intersect(bed1).size());
}
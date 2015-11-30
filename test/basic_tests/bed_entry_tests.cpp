//
// Created by petr_v on 25/11/2015.
//

#include "gtest/gtest.h"
#include "bed_entry.h"


class BedEntryTest : public testing::Test {
public:

    virtual void SetUp() {
    }
    virtual void TearDown() {
    }
private:

};

TEST(BedEntryTest, ConstructorThrowsIfWrongChromosome) {
    ASSERT_ANY_THROW(BedEntry entry("asdfa", 5, 10));
    ASSERT_ANY_THROW(BedEntry entry("chrZ", 5, 10));
    ASSERT_ANY_THROW(BedEntry entry("chr23", 5, 10));

}
TEST(BedEntryTest, ConstructorThrowsIfNegativePosition) {
    ASSERT_ANY_THROW(BedEntry entry("chr1", -5, 10));
    ASSERT_ANY_THROW(BedEntry entry("chr1", -15,-10));
    ASSERT_ANY_THROW(BedEntry entry("chr1", 15,-10));
}
TEST(BedEntryTest, ConstructorThrowsIfStartMOEThenEnd) {
    ASSERT_ANY_THROW(BedEntry entry("chr1", 15, 10));
}
TEST(BedEntryTest, ConstructorAcceptCorrectInput) {
    ASSERT_NO_THROW(BedEntry entry("chr10", 5, 10));
    ASSERT_NO_THROW(BedEntry entry("chrY", 5, 10));
}
TEST(BedEntryTest, IntersectReturnsZeroForFeaturesOnDiffChrs) {
    BedEntry first("chr1", 100, 1000);
    BedEntry second("chr2", 100, 1000);
    ASSERT_EQ(0, first.intersect(second));
}
TEST(BedEntryTest, IntersectReturnsZeroForNonIntersectingFeatures) {
    BedEntry first("chr1", 100, 1000);
    BedEntry second("chr1", 1001, 10000);
    BedEntry third("chr1", 1, 99);
    ASSERT_EQ(0, first.intersect(second));
    ASSERT_EQ(0, first.intersect(third));
}
TEST(BedEntryTest, IntersectReturnsCorrectLengthForIntersectingFeatures) {
    BedEntry first("chr1", 100, 1000);
    BedEntry second("chr1", 900, 1100);
    BedEntry third("chr1", 1, 100);
    BedEntry forth("chr1", 1000, 1150);
    BedEntry fifth("chr1", 200, 400);
    ASSERT_EQ(101, first.intersect(second));
    ASSERT_EQ(1, first.intersect(third));
    ASSERT_EQ(1, first.intersect(forth));
    ASSERT_EQ(201, first.intersect(fifth));
    ASSERT_EQ(201, fifth.intersect(first));
    ASSERT_EQ(901, first.intersect(first));
}
TEST(BedEntryTest, ComparesIfSmaller) {
    BedEntry first("chr1", 100, 1000);
    BedEntry second("chr1", 900, 1100);
    ASSERT_TRUE(first < second);
}
TEST(BedEntryTest, ComparesIfLarger) {
    BedEntry first("chr1", 100, 1000);
    BedEntry second("chr1", 900, 1100);
    ASSERT_TRUE(second > first );
}
TEST(BedEntryTest, CorrectEquality) {
    BedEntry first("chr1", 100, 1000);
    BedEntry second("chr1", 100, 1000);
    BedEntry third("chr1", 100, 1001);
    BedEntry forth("chr1", 99, 1000);
    ASSERT_TRUE(first == second);
    ASSERT_FALSE(first == third);
    ASSERT_FALSE(first == forth);
    ASSERT_FALSE(first != second);
    ASSERT_TRUE(first != third);
    ASSERT_TRUE(first != forth);
}
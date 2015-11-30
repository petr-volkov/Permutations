//
// Created by petr_v on 25/11/2015.
//

#include "gtest/gtest.h"
#include "bed_parser.h"
#include <unistd.h>

class BedParserTest : public testing::Test {
public:
    std::string correct_file;
    std::string wrong_format_file;

    virtual void SetUp() {
        correct_file = "../test/test_input/FOXA2_1.bed";
        wrong_format_file = "../test/test_input/FOXA2_1.csv";
    }
    virtual void TearDown() {

    }
private:

};

TEST_F(BedParserTest, ThrowsWithNonExistingFile) {
    ASSERT_ANY_THROW(BedParser parser("asdf"));
}

TEST_F(BedParserTest, CanBeCreated) {
    ASSERT_NO_THROW(BedParser parser(correct_file));
}

TEST_F(BedParserTest, ThrowsIfWrongFormat) {
    ASSERT_ANY_THROW(BedParser parser(wrong_format_file));
}

TEST_F(BedParserTest, ParsesCorrectNumberOfLines) {
    BedParser parser(correct_file);
    ASSERT_EQ(parser.getParsedBed().size(), 20640);
}
#include <gtest/gtest.h>
#include "tnutils.hpp"

TEST(Contains, ASCIIStringContainsChar)
{
    EXPECT_TRUE(tnUtils::contains(std::string_view("This is a test string"), 'e')) << "Failed to identify 'e' in string: \"This is a test string\"";
}

// add test for other encodings

TEST(Contains, StringDoesNotContainChar)
{
    EXPECT_FALSE(tnUtils::contains(std::string_view("This is a tst string"), 'z')) << "Identified 'z' in string: \"This is a test string\" when char is not present";
}

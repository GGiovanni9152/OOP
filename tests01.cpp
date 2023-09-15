#include <gtest/gtest.h>
#include "palindrom.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("ara") == true);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("ABOBA") == true);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("IvaN") == false);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("1") == true);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("122") == false);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("Able was I ere I saw Elba") == true);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("") == true);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("-111") == false);
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(ispalindrom("1A1") == true);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

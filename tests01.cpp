#include <gtest/gtest.h>
#include "palindrom.h"

TEST(test_01, basic_test_set)
{
    std::string input = "ara";

    bool test = ispalindrom(input);

    EXPECT_TRUE(test);
}

TEST(test_02, basic_test_set)
{
    std::string input = "ABOBA";

    bool test = ispalindrom(input);

    EXPECT_TRUE(test);
}

TEST(test_03, basic_test_set)
{
    std::string input = "IvaN";

    bool test = ispalindrom(input);
    
    EXPECT_FALSE(test);
}

TEST(test_04, basic_test_set)
{
    std::string input = "1";

    bool test = ispalindrom(input);
    
    EXPECT_TRUE(test);
}

TEST(test_05, basic_test_set)
{
    std::string input = "122";

    bool test = ispalindrom(input);
    
    EXPECT_FALSE(test);
}

TEST(test_06, basic_test_set)
{
    std::string input = "Able was I ere I saw Elba";

    bool test = ispalindrom(input);
    
    EXPECT_TRUE(test);
}

TEST(test_07, basic_test_set)
{
    std::string input = "";

    bool test = ispalindrom(input);
    
    EXPECT_TRUE(test);
}

TEST(test_08, basic_test_set)
{
    std::string input = "-111";

    bool test = ispalindrom(input);
    
    EXPECT_FALSE(test);
}

TEST(test_09, basic_test_set)
{
    std::string input = "1A1";

    bool test = ispalindrom(input);
    
    EXPECT_TRUE(test);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

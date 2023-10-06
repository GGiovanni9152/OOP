#include <iostream>
#include <string>
#include "include/Four.h"
#include <fstream>
#include <gtest/gtest.h>


TEST(TestGroupName, Constructor_default)
{
    bool test = true;
    try
    {
        Four new_four;
    }
    
    catch(std::bad_alloc &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        test = false;
    }
    
    EXPECT_TRUE(test);
}

TEST(TestGroupName, Constructor_fill)
{
    bool test = true;
    int size = 10;
    try
    {
        Four new_four(10, '1');
    }
    
    catch(std::bad_alloc &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        test = false;
    }
    
    EXPECT_TRUE(test);
    test = false;
    try
    {
        Four second_four(size, '5');
    }
    catch(std::invalid_argument &ex)
    {
        std::cout << "Exception: " << ex.what() <<std::endl;
        test = true;
    }
    
    EXPECT_TRUE(test);
}

TEST(TestGroupName, Constructor_initializer_list)
{
    bool test = true;
    try
    {
        Four new_four{'1','2'};
    }
    
    catch(std::bad_alloc &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        test = false;
    }
    
    EXPECT_TRUE(test);
    
    test = false;
    try
    {
        Four second_four{'5','6'};
    }
    catch(std::invalid_argument &ex)
    {
        std::cout << "Exception: " << ex.what() <<std::endl;
        test = true;
    }
    
    EXPECT_TRUE(test);
}

TEST(TestGroupName, string_constructor)
{
    bool test = true;
    std::string str = "123";
    try
    {
        Four new_four(str);
    }
    
    catch(std::bad_alloc &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        test = false;
    }
    
    EXPECT_TRUE(test);
}

TEST(TestGroupName, copy_constructor)
{
    bool test = true;
    std::string str = "123";
    Four first_four(str);
    
    try
    {
        Four second_four(first_four);
    }
    catch(std::bad_alloc &ex)
    {
        std::cerr << "Exception: " << ex.what() << std::endl;
        test = false;
    }
    
    EXPECT_TRUE(test);
    
    Four second_four(first_four);
    bool res;
    res = (first_four == second_four);
    
    EXPECT_TRUE(res);
}

TEST(TestGroupName, test_equal)
{
    Four first_four{'1','2','3'};
    Four second_four{'1','2','3'};
    Four third_four{'2','2','2'};
    
    bool res;
    
    res = (first_four == first_four);
    EXPECT_TRUE(res);
    
    res = (first_four == second_four);
    EXPECT_TRUE(res);
    
    res = (first_four == third_four);
    EXPECT_FALSE(res);
}

TEST(TestGroupName, test_greater)
{
    std::string str1 = "123";
    std::string str2 = "321";
    std::string str3 = "3212";
    
    Four first_four;
    Four second_four(str1);
    Four third_four(str2);
    Four fourth_four(str3);
    
    bool res;
    
    res = (second_four > fourth_four);
    EXPECT_TRUE(res);
    
    res = (second_four > first_four);
    EXPECT_TRUE(res);
    
    res = (third_four > second_four);
    EXPECT_TRUE(res);
    
    res = (fourth_four > first_four);
    EXPECT_FALSE(res);
    
    res = (first_four > second_four);
    EXPECT_FALSE(res);
    
    res = (second_four > third_four);
    EXPECT_FALSE(res);
    
}

TEST(TestGroupName, test_less)
{
    std::string str1 = "123";
    std::string str2 = "321";
    std::string str3 = "3212";
    
    Four first_four;
    Four second_four(str1);
    Four third_four(str2);
    Four fourth_four(str3);
    
    bool res;
    
    res = (second_four < fourth_four);
    EXPECT_FALSE(res);
    
    res = (second_four < first_four);
    EXPECT_FALSE(res);
    
    res = (third_four < second_four);
    EXPECT_FALSE(res);
    
    res = (fourth_four < first_four);
    EXPECT_TRUE(res);
    
    res = (first_four < second_four);
    EXPECT_TRUE(res);
    
    res = (second_four < third_four);
    EXPECT_TRUE(res);
    
}

TEST(TestGroupName, test_sum)
{
    std::string str1 = "123";
    std::string str2 = "12";
    std::string str3 = "201";
    std::string str4 = "312";
    
    Four first_four;
    Four second_four(str1);
    Four third_four(str2);
    Four fourth_four(str3);
    Four fifth_four(str4);
    
    EXPECT_TRUE(first_four == (first_four + first_four));
    EXPECT_TRUE(fourth_four == (second_four + third_four));
    EXPECT_TRUE(fifth_four == (second_four + second_four));
}

TEST(TestGroupName, test_minus)
{
    std::string str1 = "123";
    std::string str2 = "312";
    std::string str3 = "23";
    std::string str4 = "100";
    
    Four first_four;
    Four second_four(str1);
    Four third_four(str2);
    Four fourth_four(str3);
    Four sixth_four(str4);
    
    bool res;
    
    res = (second_four == (third_four - second_four));
    EXPECT_TRUE(res);
    
    res = (sixth_four == (second_four - fourth_four));
    EXPECT_TRUE(res);
    
    res = (second_four == (second_four - first_four));
    EXPECT_TRUE(res);
}

TEST(TestGroupName, file_test)
{
    Four first_four;
    Four second_four("201");
    Four third_four;
    
    first_four.read_from_file("input.txt");
    first_four -= second_four;
    first_four.save_to_file("output.txt");
    
    third_four.read_from_file("input.txt");
    
    bool res = (third_four == first_four);
    EXPECT_TRUE(res);
    
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    
    return RUN_ALL_TESTS();
}

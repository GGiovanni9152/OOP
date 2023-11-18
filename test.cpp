#include "googletest/googletest/include/gtest/gtest.h"
#include <iostream>
#include "List.h"
#include "Allocator.h"
#include "Factorial.h"

const int factorial_summ = 409114;

TEST(test_01, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);

    int cmp = *(list.begin());
    bool res = false;

    if (cmp == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_02, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);

    int cmp = *(list.cbegin());
    bool res = false;

    if (cmp == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_03, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);

    auto val = list.insert(++++list.begin(), x5);
    list.erase(++++list.begin());

    int cmp = list[2];
    bool res = false;

    if (cmp == 3)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_04, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);

    auto val = list.insert(++++list.begin(), x5);
    list.erase(++++list.begin());

    int cmp = list.front();
    bool res = false;

    if (cmp == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_05, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);

    auto val = list.insert(++++list.begin(), x5);
    list.erase(++++list.begin());

    int cmp = list.back();
    bool res = false;

    if (cmp == 4)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_06, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);

    bool cmp = list.empty();

    EXPECT_FALSE(cmp);
}

TEST(test_07, basic_test_set)
{
    List<int, mai::Allocator<int>> list;

    bool cmp = list.empty();

    EXPECT_TRUE(cmp);
}

TEST(test_08, basic_test_set)
{
    mapa map;
    fill_map(map, 10);

    int summa = 0;

    for (auto elem : map)
    {
        summa += elem.second;
    }

    bool res = false;

    if (summa == factorial_summ) // 409114 - 0! + 1! + ... + 9!
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

int main(int argc, char** argv)
{

    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
#include <gtest/gtest.h>
#include "include/Square.h"


TEST(test_01, basic_test_set)
{
    Point a(1, 2);

    bool res = false;
    
    if (a.X() == 1 && a.Y() == 2)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_02, basic_test_set)
{
    Point a(1, 2);
    Point b(1, 2);
    Point c;

    bool res = false;
    c = a + b;
    if (c.X() == 2 && c.Y() == 4)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_03, basic_test_set)
{
    Point a(1, 2);
    Point b(1, 2);
    Point c;

    bool res = false;
    c = a + b;
    c = c / 2;

    if (c == a)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_04, basic_test_set)
{
    Point a(0, 0);
    Point b(1, 1);
    Vector ab(a, b);

    bool res = false;

    if (ab.X() == 1 && ab.Y() == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_05, basic_test_set)
{
    Point a(0, 0);
    Point b(1, 1);

    Vector ab(a, b);
    Vector ac = ab + ab;

    double scalar = ab * ac; 

    bool res = false;

    if (scalar == 4)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_06, basic_test_set)
{
    Vector ab(1, 0);

    bool res = false;

    if (ab.length() == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_07, basic_test_set)
{
    Vector ab(1, 0);
    Vector cd(0, 1);

    bool res = false;

    if (isParallel(ab, cd))
    {
        res = true;
    }

    EXPECT_FALSE(res);
}

TEST(test_08, basic_test_set)
{
    Point a(1, 2);
    Point b(3, 2);
    Point c(3, 1);
    Point d(1, 1);

    Rectangle s(a, b, c, d);
    Rectangle y;
    y = s;

    bool res = false;

    if (y == s)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_09, basic_test_set)
{
    Point a(1, 2);
    Point b(3, 2);
    Point c(3, 1);
    Point d(1, 1);

    Rectangle s(a, b, c, d);

    bool res = false;

    if (s.area() == 2 && static_cast<double> (s) == 2)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_10, basic_test_set)
{
    Point a(1, 2);
    Point b(3, 2);
    Point c(3, 1);
    Point d(1, 1);
    Point center(2, 1.5);

    Rectangle s(a, b, c, d);

    bool res = false;

    if (s.center() == center)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_11, basic_test_set)
{
    Point a(1, 1);
    Point b(1, 2);
    Point c(2, 2);
    Point d(2, 1);

    Square s(a, b, c, d);

    bool res = false;

    if (s.area() == 1 && static_cast<double> (s) == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_12, basic_test_set)
{
    Point a(1, 1);
    Point b(1, 2);
    Point c(2, 2);
    Point d(2, 1);
    Point center(1.5, 1.5);

    Square s(a, b, c, d);

    bool res = false;

    if (s.center() == center)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
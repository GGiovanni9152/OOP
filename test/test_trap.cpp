#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "Trapezium.h"

TEST(test_01, basic_test_set)
{
    Point a(3, 3);
    Point b(4, 1);
    Point c(1, 1);
    Point d(2, 3);
    Point center(2.5, 2);

    Trapezium trapecia(a, b, c, d);

    bool res = false;
    
    if (trapecia.center() == center)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_02, basic_test_set)
{
    Point a(3, 3);
    Point b(4, 1);
    Point c(1, 1);
    Point d(2, 3);

    Trapezium trapecia(a, b, c, d);

    bool res = false;
    
    if (trapecia.area() == 4 && static_cast<double>(trapecia) == 4)
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
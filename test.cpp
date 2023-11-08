#include "googletest/googlemock/include/gmock/gmock.h"
#include "googletest/googletest/include/gtest/gtest.h"
#include "Square.h"
#include "Din_Array.h"
#include "Trapezium.h"


TEST(test_01, basic_test_set)
{
    Point<double> a(1., 2.);

    bool res = false;
    
    if (a.X() == 1 && a.Y() == 2)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_02, basic_test_set)
{
    Point<double> a(1., 2.);
    Point<double> b(1., 2.);
    Point<double> c;

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
    Point<double> a(1., 2.);
    Point<double> b(1., 2.);
    Point<double> c;

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
    Point<double> a(0., 0.);
    Point<double> b(1., 1.);
    Vector<double> ab(a, b);

    bool res = false;

    if (ab.X() == 1 && ab.Y() == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_05, basic_test_set)
{
    Point<double> a(0., 0.);
    Point<double> b(1., 1.);

    Vector<double> ab(a, b);
    Vector<double> ac = ab + ab;

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
    Vector<double> ab(1., 0.);

    bool res = false;

    if (ab.length() == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_07, basic_test_set)
{
    Vector<double> ab(1., 0.);
    Vector<double> cd(0., 1.);

    bool res = false;

    if (isParallel(ab, cd))
    {
        res = true;
    }

    EXPECT_FALSE(res);
}

TEST(test_08, basic_test_set)
{
    Point<double> a(1., 2.);
    Point<double> b(3., 2.);
    Point<double> c(3., 1.);
    Point<double> d(1., 1.);

    Rectangle<double> s(a, b, c, d);
    Rectangle<double> y;
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
    Point<double> a(1., 2.);
    Point<double> b(3., 2.);
    Point<double> c(3., 1.);
    Point<double> d(1., 1.);

    Rectangle<double> s(a, b, c, d);

    bool res = false;

    if (s.area() == 2 && static_cast<double> (s) == 2)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_10, basic_test_set)
{
    Point<double> a(1., 2.);
    Point<double> b(3., 2.);
    Point<double> c(3., 1.);
    Point<double> d(1., 1.);
    Point<double> center(2., 1.5);

    Rectangle<double> s(a, b, c, d);

    bool res = false;

    if (s.center() == center)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_11, basic_test_set)
{
    Point<double> a(1., 1.);
    Point<double> b(1., 2.);
    Point<double> c(2., 2.);
    Point<double> d(2., 1.);

    Square<double> s(a, b, c, d);

    bool res = false;

    if (s.area() == 1 && static_cast<double> (s) == 1)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_12, basic_test_set)
{
    Point<double> a(1., 1.);
    Point<double> b(1., 2.);
    Point<double> c(2., 2.);
    Point<double> d(2., 1.);
    Point<double> center(1.5, 1.5);

    Square<double> s(a, b, c, d);

    bool res = false;

    if (s.center() == center)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_13, basic_test_set)
{
    Point<double> a(3., 3.);
    Point<double> b(4., 1.);
    Point<double> c(1., 1.);
    Point<double> d(2., 3.);
    Point<double> center(2.5, 2);

    Trapezium trapecia(a, b, c, d);

    bool res = false;
    
    if (trapecia.center() == center)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_14, basic_test_set)
{
    Point<double> a(3., 3.);
    Point<double> b(4., 1.);
    Point<double> c(1., 1.);
    Point<double> d(2., 3.);

    Trapezium trapecia(a, b, c, d);

    bool res = false;
    
    if (trapecia.area() == 4 && static_cast<double>(trapecia) == 4)
    {
        res = true;
    }

    EXPECT_TRUE(res);
}

TEST(test_15, basic_test_set)
{
    Point <double> a(3., 3.); //Trapezium
    Point <double> b(4., 1.);
    Point <double> c(1., 1.);
    Point <double> d(2., 3.);

    Point <double> e(1., 1.); //Square
    Point <double> f(1., 2.);
    Point <double> g(2., 2.);
    Point <double> h(2., 1.);

    Point <double> x(1., 2.); //Rectangle
    Point <double> y(3., 2.);
    Point <double> z(3., 1.);
    Point <double> s(1., 1.);

    Array<std::shared_ptr<Figure<double>>> array {
                                            std::make_shared <Trapezium <double>>(a, b, c, d),
                                            std::make_shared <Rectangle <double>> (x, y, z, s),
                                            std::make_shared <Square <double>> (e, f, g, h)

    };

    bool res = false;

    double square = 0.;
    square = array.total_area();

    if (square == 7)
    {
        res = true;
    }

    EXPECT_TRUE(res);

}

TEST(test_16, basic_test_set)
{
    Point <double> a(3., 3.); //Trapezium
    Point <double> b(4., 1.);
    Point <double> c(1., 1.);
    Point <double> d(2., 3.);

    Point <double> e(1., 1.); //Square
    Point <double> f(1., 2.);
    Point <double> g(2., 2.);
    Point <double> h(2., 1.);

    Point <double> x(1., 2.); //Rectangle
    Point <double> y(3., 2.);
    Point <double> z(3., 1.);
    Point <double> s(1., 1.);

    Array<std::shared_ptr<Figure<double>>> array {
                                            std::make_shared <Trapezium <double>>(a, b, c, d),
                                            std::make_shared <Rectangle <double>> (x, y, z, s),
                                            std::make_shared <Square <double>> (e, f, g, h)

    };

    bool res = false;

    array.remove_element(0);
    double square = 0.;
    square = array.total_area();

    if (square == 3)
    {
        res = true;
    }

    EXPECT_TRUE(res);

}

TEST(test_17, basic_test_set)
{
    Point <double> a(3., 3.); //Trapezium
    Point <double> b(4., 1.);
    Point <double> c(1., 1.);
    Point <double> d(2., 3.);

    Point <double> e(1., 1.); //Square
    Point <double> f(1., 2.);
    Point <double> g(2., 2.);
    Point <double> h(2., 1.);

    Point <double> x(1., 2.); //Rectangle
    Point <double> y(3., 2.);
    Point <double> z(3., 1.);
    Point <double> s(1., 1.);

    Array<std::shared_ptr<Figure<double>>> array {
                                            std::make_shared <Trapezium <double>>(a, b, c, d),
                                            std::make_shared <Rectangle <double>> (x, y, z, s),
                                            std::make_shared <Square <double>> (e, f, g, h)

    };

    bool res = false;

    double square = 0.;
    square = array.element_area(0);

    if (square == 4)
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
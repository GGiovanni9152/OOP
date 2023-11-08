#pragma once
#include <iostream>
#include "Figure.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
class Rectangle: public Figure<T>
{
    public:
        Rectangle();
        Rectangle(const Point<T> &a, const Point<T> &b, const Point<T> &c,  const Point<T> &d);
        Rectangle(const Rectangle &other);
        Rectangle(const Rectangle &&other);

        Rectangle& operator= (const Rectangle &other);
        bool operator== (const Rectangle &other);

        Point<T> center() const override;
        T area() const override;
        operator double() const override;

        ~Rectangle() = default;
        
    protected:
        std::ostream& print(std::ostream &out) const override;
        std::istream& input(std::istream &in) override;

        Point<T> _a, _b, _c, _d;
        
};

#include "../src/Rectangle.cpp"
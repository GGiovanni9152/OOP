#pragma once
#include "Rectangle.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
class Square final: public Rectangle<T>
{
    using Rectangle<T>::_a;
    using Rectangle<T>::_b;
    using Rectangle<T>::_c;
    using Rectangle<T>::_d;
    public:
        Square() : Rectangle<T>() {}
        Square(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d);

        std::ostream& print(std::ostream &out) const override;

        ~Square() = default;
};

#include "../src/Square.cpp"
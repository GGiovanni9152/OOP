#pragma once
#include <iostream>
#include "../include/Point.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
class Vector
{
    public:
        Vector();
        Vector(T x, T y);
        Vector(const Point<T> &begin, const Point<T> &end);
        Vector(const Vector &other);

        T operator* (const Vector &other);
        Vector operator+ (const Vector &other);
        Vector operator- (const Vector &other);
        Vector operator= (const Vector &other);

        T X() const;
        T Y() const;
        T length();

    private:
        T _x, _y;
};

template <typename T>
bool isParallel(const Vector<T> &first, const Vector<T> &second);

#include "../src/Vector.cpp"

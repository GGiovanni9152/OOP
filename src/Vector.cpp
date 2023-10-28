#include <iostream>
#include <cmath>
#include "Vector.h"

Vector::Vector() = default;
Vector::Vector(double x, double y): _x(x), _y(y){};
Vector::Vector(const Point &begin, const Point &end)
{
    _x = end.X() - begin.X();
    _y = end.Y() - begin.Y();
}

Vector::Vector(const Vector &other)
{
    _x = other._x;
    _y = other._y;
}

double Vector::operator* (const Vector &other)
{
    return (_x * other._x) + (_y * other._y);
}

Vector Vector::operator+ (const Vector &other)
{
    Vector tmp;
    tmp._x = _x + other._x; 
    tmp._y = _y + other._y;
    return tmp;
}

Vector Vector::operator- (const Vector &other)
{
    Vector tmp;
    tmp._x = _x - other._x; 
    tmp._y = _y - other._y;
    return tmp;
}

Vector Vector::operator= (const Vector &other)
{
    _x = other._x;
    _y = other._y;
    return *this;
}

double Vector::X() const
{
    return _x;
}
double Vector::Y() const
{
    return _y;
}

double Vector::length()
{
    return sqrt(_x * _x + _y * _y);
}

bool isParallel(const Vector &first, const Vector &second)
{
    return ((first.X() * second.Y() - first.Y() * second.X()) == 0);
}
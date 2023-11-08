#include <iostream>
#include <cmath>
#include "../include/Vector.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T>::Vector() = default;

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T>::Vector(T x, T y): _x(x), _y(y){};

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T>::Vector(const Point<T> &begin, const Point<T> &end)
{
    _x = end.X() - begin.X();
    _y = end.Y() - begin.Y();
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T>::Vector(const Vector &other)
{
    _x = other._x;
    _y = other._y;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Vector<T>::operator* (const Vector &other)
{
    return (_x * other._x) + (_y * other._y);
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T> Vector<T>::operator+ (const Vector &other)
{
    Vector tmp;
    tmp._x = _x + other._x; 
    tmp._y = _y + other._y;
    return tmp;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T> Vector<T>::operator- (const Vector &other)
{
    Vector tmp;
    tmp._x = _x - other._x; 
    tmp._y = _y - other._y;
    return tmp;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Vector<T> Vector<T>::operator= (const Vector &other)
{
    _x = other._x;
    _y = other._y;
    return *this;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Vector<T>::X() const
{
    return _x;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Vector<T>::Y() const
{
    return _y;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Vector<T>::length()
{
    return sqrt(_x * _x + _y * _y);
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
bool isParallel(const Vector<T> &first, const Vector<T> &second)
{
    return ((first.X() * second.Y() - first.Y() * second.X()) == 0);
}
#include "../include/Point.h"
#include <limits>

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(): _x(0), _y(0) {};

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(T x, T y): _x(x), _y(y){};

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(const Point &other)
{
    _x = other._x;
    _y = other._y;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T>::Point(const Point &&other) noexcept
{
    _x = other._x;
    _y = other._y;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Point<T>::X() const
{
    return _x;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Point<T>::Y() const
{
    return _y;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> Point<T>::operator=(const Point &other)
{
    _x = other._x;
    _y = other._y;
    return *this;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
bool Point<T>::operator==(const Point &other) const
{
    return (_x - other._x <= std::numeric_limits<double>::epsilon()) &&
    (_y - other._y <= std::numeric_limits<double>::epsilon());
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> Point<T>::operator+ (const Point &other) const
{
    Point tmp;
    tmp._x = _x + other._x;
    tmp._y = _y + other._y;
    return tmp;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> Point<T>::operator/ (const T &a) const
{
    Point tmp;
    tmp._x = _x / a;
    tmp._y = _y / a;
    return tmp;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream& operator<<(std::ostream &out, const Point<T> &point)
{
    out << point._x << ',' << point._y;
    return out;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::istream& operator>>(std::istream& in, Point<T> &point)
{
    in >> point._x >> point._y;
    return in;
}
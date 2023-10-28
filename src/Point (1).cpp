#include "Point.h"
#include <limits>

Point::Point(): _x(0), _y(0) {};
Point::Point(double x, double y): _x(x), _y(y){};
Point::Point(const Point &other)
{
    _x = other._x;
    _y = other._y;
}

Point::Point(const Point &&other) noexcept
{
    _x = other._x;
    _y = other._y;
}

double Point::X() const
{
    return _x;
}

double Point::Y() const
{
    return _y;
}

Point Point::operator=(const Point &other)
{
    _x = other._x;
    _y = other._y;
    return *this;
}

bool Point::operator==(const Point &other) const
{
    return (_x - other._x <= std::numeric_limits<double>::epsilon()) &&
    (_y - other._y <= std::numeric_limits<double>::epsilon());
}

Point Point::operator+ (const Point &other) const
{
    Point tmp;
    tmp._x = _x + other._x;
    tmp._y = _y + other._y;
    return tmp;
}

Point Point::operator/ (const double &a) const
{
    Point tmp;
    tmp._x = _x / a;
    tmp._y = _y / a;
    return tmp;
}

std::ostream& operator<<(std::ostream &out, const Point &point)
{
    out << point._x << ',' << point._y;
    return out;
}

std::istream& operator>>(std::istream& in, Point &point)
{
    in >> point._x >> point._y;
    return in;
}
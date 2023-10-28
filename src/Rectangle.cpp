#include <iostream>
#include <limits>
#include <cmath>
#include "Rectangle.h"

Rectangle::Rectangle() = default;

Rectangle::Rectangle(const Point &a, const Point &b, const Point &c, const Point &d): _a(a), _b(b), _c(c), _d(d)
{
    Vector ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d);
    
    if(!isParallel(ab, cd))
    {
        std::swap(_b, _c);
        
        ab = {_a, _b};
        bc = {_b, _c};
        ad = {_a, _d};
        cd = {_c, _d};
    }
    
    if (!isParallel(ad, bc))
    {
        std::swap(_a, _b);
        
        ab = {_a, _b};
        bc = {_b, _c};
        ad = {_a, _d};
        cd = {_c, _d};
    }
    
    if (ab * bc || bc * cd || cd * ad || ad * ab)
    {
        throw std::logic_error("Not perpendicular sides\n");
    }
    
    if ((ab.length() != cd.length()) || (bc.length() != (ad.length())))
    {
        throw std::logic_error("Parallel sides are not equal\n");
    }
    
    if (!ab.length() || !bc.length())
    {
        throw std::logic_error("Sides can't be zero\n");
    }
}

Rectangle::Rectangle(const Rectangle &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

Rectangle::Rectangle(const Rectangle &&other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

Rectangle& Rectangle::operator= (const Rectangle &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    return *this;
}

bool Rectangle::operator== (const Rectangle &other)
{
    return (_a == other._a) && (_b == other._b) && (_c == other._c) && (_d == other._d);
}

Rectangle::operator double() const
{
    Vector ab(_a, _b);
    Vector bc(_b, _c);
    return ab.length() * bc.length();
}

Point Rectangle::center() const
{
    return (_a + _b + _c + _d) / 4;
}

double Rectangle::area() const
{
    Vector ab(_a, _b);
    Vector bc(_b, _c);
    return ab.length() * bc.length();
}

std::ostream& Rectangle::print(std::ostream &out) const
{
    out << "Rectangle [" << _a << ';' << _b << ';' << _c << ';' << _d << ']';
    return out;
}

std::istream& Rectangle::input(std::istream &in)
{
    //Point a, b, c, d;
    in >> _a >> _b >> _c >> _d;
    //Rectangle tmp = Rectangle(a, b, c, d);
    Rectangle(_a, _b, _c, _d);
    return in;
}
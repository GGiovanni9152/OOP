#include <iostream>
#include <limits>
#include <cmath>
#include "../include/Rectangle.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
Rectangle<T>::Rectangle() = default;

template <typename T>
requires std::integral<T> || std::floating_point<T>
Rectangle<T>::Rectangle(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d): _a(a), _b(b), _c(c), _d(d)
{
    Vector<T> ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d);
    
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

template <typename T>
requires std::integral<T> || std::floating_point<T>
Rectangle<T>::Rectangle(const Rectangle<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Rectangle<T>::Rectangle(const Rectangle<T> &&other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Rectangle<T>& Rectangle<T>::operator= (const Rectangle<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    return *this;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
bool Rectangle<T>::operator== (const Rectangle<T> &other)
{
    return (_a == other._a) && (_b == other._b) && (_c == other._c) && (_d == other._d);
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Rectangle<T>::operator double() const
{
    Vector ab(_a, _b);
    Vector bc(_b, _c);
    return ab.length() * bc.length();
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> Rectangle<T>::center() const
{
    return (_a + _b + _c + _d) / 4;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Rectangle<T>::area() const
{
    Vector<T> ab(_a, _b);
    Vector<T> bc(_b, _c);
    return ab.length() * bc.length();
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream& Rectangle<T>::print(std::ostream &out) const
{
    out << "Rectangle [" << _a << ';' << _b << ';' << _c << ';' << _d << ']';
    return out;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::istream& Rectangle<T>::input(std::istream &in)
{
    //Point a, b, c, d;
    in >> _a >> _b >> _c >> _d;
    //Rectangle tmp = Rectangle(a, b, c, d);
    Rectangle<T>(_a, _b, _c, _d);
    return in;
}
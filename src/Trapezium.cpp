#include "../include/Trapezium.h"
#include <cmath>

template <typename T>
requires std::integral<T> || std::floating_point<T>
Trapezium<T>::Trapezium() = default;

template <typename T>
requires std::integral<T> || std::floating_point<T>
Trapezium<T>::Trapezium(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d)
{
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    Vector<T> ab(a, b), bc(b, c), cd(c, d), ad(a, d);

    if (!isParallel(ab, cd) && !isParallel(bc, ad))
    {
        std::swap(_a, _c);
        ab = Vector<T>(a, b);
        cd = Vector<T>(c, d);
        ad = Vector<T>(a, d);
        bc = Vector<T>(b, c);
    }

    if (!isParallel(ab, cd) && !isParallel(bc, ad))
    {
        throw std::logic_error("No parallel sides\n");
    }

    if(!ab.length() || !bc.length() || !cd.length() || !ad.length())
    {
        throw std::logic_error("Sides can't be zero\n");
    }
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Trapezium<T>::Trapezium(const Trapezium<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Trapezium<T>::Trapezium(const Trapezium<T> &&other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Trapezium<T>& Trapezium<T>::operator= (const Trapezium<T> &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    return *this;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
bool Trapezium<T>::operator== (const Trapezium<T> &other)
{
    return (_a == other._a) && (_b == other._b) && (_c == other._c) && (_d == other._d);
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Trapezium<T>::operator double() const 
{
    Vector<T> ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d); 

    if(isParallel(ab, cd)) 
    {
        std::swap(ab, bc);
        std::swap(cd, ad);
    }

    if(bc.length() < ad.length())
    {
        std::swap(bc, ad);
    }

    T h = sqrt((bc.X() - ad.X()) * (bc.X() - ad.X()) - (bc.Y() - ad.Y()) * (bc.Y() - ad.Y()));
    return h * (bc.length() + ad.length()) / 2;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
Point<T> Trapezium<T>::center() const //ad, bc - osnov, bc > ad
{
    Vector<T> ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d); 
    
    if(isParallel(ab, cd)) 
    {
        std::swap(ab, bc);
        std::swap(cd, ad);
    }

    if(bc.length() < ad.length())
    {
        std::swap(bc, ad);
    }

    T min_y = std::min(_a.Y(), std::min(_b.Y(), std::min(_c.Y(), _d.Y())));
    T min_x = std::min(_a.X(), std::min(_b.X(), std::min(_c.X(), _d.X())));

    T h = sqrt((bc.X() - ad.X()) * (bc.X() - ad.X()) - (bc.Y() - ad.Y()) * (bc.Y() - ad.Y()));

    //std::cout << bc.X() << ' ' << bc.Y() << ' ' << ad.X() << ' ' << ad.Y() << '\n';
    //std::cout << min_y << ' ' << min_x << ' ' << h << '\n';

    Point<T> cent(min_x + bc.length() / 2.0, (min_y + h) / 2.0); 

    return cent;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
T Trapezium<T>::area() const
{
    Vector<T> ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d); 

    if(isParallel(ab, cd)) 
    {
        std::swap(ab, bc);
        std::swap(cd, ad);
    }

    if(bc.length() < ad.length())
    {
        std::swap(bc, ad);
    }

    T h = sqrt((bc.X() - ad.X()) * (bc.X() - ad.X()) - (bc.Y() - ad.Y()) * (bc.Y() - ad.Y()));
    return h * (bc.length() + ad.length()) / 2.0;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream &Trapezium<T>::print(std::ostream &out) const
{
    out << "Trapezium [" << _a << ';' << _b << ';' << _c << ';' << _d << ']';
    return out;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::istream &Trapezium<T>::input(std::istream &in)
{
    in >> _a >> _b >> _c >> _d;
    return in;
}
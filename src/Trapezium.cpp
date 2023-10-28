#include "Trapezium.h"
#include <cmath>

Trapezium::Trapezium() = default;
Trapezium::Trapezium(const Point &a, const Point &b, const Point &c, const Point &d)
{
    _a = a;
    _b = b;
    _c = c;
    _d = d;
    Vector ab(a, b), bc(b, c), cd(c, d), ad(a, d);

    if (!isParallel(ab, cd) && !isParallel(bc, ad))
    {
        std::swap(_a, _c);
        ab = Vector(a, b);
        cd = Vector(c, d);
        ad = Vector(a, d);
        bc = Vector(b, c);
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

Trapezium::Trapezium(const Trapezium &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

Trapezium::Trapezium(const Trapezium &&other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
}

Trapezium& Trapezium::operator= (const Trapezium &other)
{
    _a = other._a;
    _b = other._b;
    _c = other._c;
    _d = other._d;
    return *this;
}

bool Trapezium::operator== (const Trapezium &other)
{
    return (_a == other._a) 
            && (_b == other._b)
            && (_c == other._c) 
            && (_d == other._d);
}

Trapezium::operator double() const 
{
    Vector ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d); 

    if(isParallel(ab, cd)) 
    {
        std::swap(ab, bc);
        std::swap(cd, ad);
    }

    if(bc.length() < ad.length())
    {
        std::swap(bc, ad);
    }

    double h = sqrt((bc.X() - ad.X()) * (bc.X() - ad.X()) - (bc.Y() - ad.Y()) * (bc.Y() - ad.Y()));
    return h * (bc.length() + ad.length()) / 2;
}

Point Trapezium::center() const //ad, bc - osnov, bc > ad
{
    Vector ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d); 
    
    if(isParallel(ab, cd)) 
    {
        std::swap(ab, bc);
        std::swap(cd, ad);
    }

    if(bc.length() < ad.length())
    {
        std::swap(bc, ad);
    }

    double min_y = std::min(_a.Y(), std::min(_b.Y(), std::min(_c.Y(), _d.Y())));
    double min_x = std::min(_a.X(), std::min(_b.X(), std::min(_c.X(), _d.X())));

    double h = sqrt((bc.X() - ad.X()) * (bc.X() - ad.X()) - (bc.Y() - ad.Y()) * (bc.Y() - ad.Y()));

    std::cout << bc.X() << ' ' << bc.Y() << ' ' << ad.X() << ' ' << ad.Y() << '\n';
    std::cout << min_y << ' ' << min_x << ' ' << h << '\n';

    Point cent(min_x + bc.length() / 2.0, min_y + h / 2.0); 

    return cent;
}

double Trapezium::area() const
{
    Vector ab(_a, _b), bc(_b, _c), cd(_c, _d), ad(_a, _d); 

    if(isParallel(ab, cd)) 
    {
        std::swap(ab, bc);
        std::swap(cd, ad);
    }

    if(bc.length() < ad.length())
    {
        std::swap(bc, ad);
    }

    double h = sqrt((bc.X() - ad.X()) * (bc.X() - ad.X()) - (bc.Y() - ad.Y()) * (bc.Y() - ad.Y()));
    return h * (bc.length() + ad.length()) / 2.0;
}


std::ostream &Trapezium::print(std::ostream &out) const
{
    out << "Trapezium [" << _a << ';' << _b << ';' << _c << ';' << _d << ']';
    return out;
}

std::istream &Trapezium::input(std::istream &in)
{
    in >> _a >> _b >> _c >> _d;
    return in;
}
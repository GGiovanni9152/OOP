#include "../include/Square.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
Square<T>::Square(const Point<T>& a, const Point<T>& b, const Point<T> &c, const Point<T>& d)
{
    Rectangle(a, b, c, d);
    Vector<T> ab(a, b), ad(a, d), bc(b, c), cd(c, d);

    if (ab.length() != ad.length() || ab.length() != bc.length() || ab.length() != cd.length())
    {
        throw std::logic_error("Sides aren't equal\n");
    }

    _a = a;
    _b = b;
    _c = c;
    _d = d;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream& Square<T>::print(std::ostream &out) const
{
    out << "Square [" << _a << ';' << _b << ';' << _c << ';' << _d << ']';
    return out;
}
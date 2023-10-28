#include "Square.h"

Square::Square(const Point& a, const Point& b, const Point &c, const Point& d)
{
    Rectangle(a, b, c, d);
    Vector ab(a, b), ad(a, d), bc(b, c), cd(c, d);

    if (ab.length() != ad.length() || ab.length() != bc.length() || ab.length() != cd.length())
    {
        throw std::logic_error("Sides aren't equal\n");
    }
}

std::ostream& Square::print(std::ostream &out) const
{
    out << "Square [" << _a << ';' << _b << ';' << _c << ';' << _d << ']';
    return out;
}
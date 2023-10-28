#include "Figure.h"

std::ostream& operator<< (std::ostream &out, const Figure &figure)
{
    figure.print(out);
    return out;
}
std::istream& operator>> (std::istream &in, Figure &figure)
{
    figure.input(in);
    return in;
}

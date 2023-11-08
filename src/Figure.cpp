#include "../include/Figure.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::ostream& operator<< (std::ostream &out, const Figure<T> &figure)
{
    figure.print(out);
    return out;
}

template <typename T>
requires std::integral<T> || std::floating_point<T>
std::istream& operator>> (std::istream &in, Figure<T> &figure)
{
    figure.input(in);
    return in;
}

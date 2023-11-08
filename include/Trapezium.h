#pragma once
#include "Figure.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
class Trapezium final: public Figure<T>
{
    public:
        Trapezium();
        Trapezium(const Point<T> &a, const Point<T> &b, const Point<T> &c, const Point<T> &d);
        Trapezium(const Trapezium &other);
        Trapezium(const Trapezium &&other);

        Trapezium& operator= (const Trapezium &other);
        bool operator== (const Trapezium &other);
        
        Point<T> center() const override;
        T area() const override;
        operator double() const override;

        ~Trapezium() = default;

    private:
        std::ostream& print(std::ostream &out) const override;
        std::istream& input(std::istream &in) override;

        Point<T> _a, _b, _c, _d;
};

#include "../src/Trapezium.cpp"
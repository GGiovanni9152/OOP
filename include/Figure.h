#pragma once
#include <iostream>
#include "../include/Vector.h"

template <typename T>
requires std::integral<T> || std::floating_point<T>
class Figure
{
    public:
        virtual Point<T> center() const = 0;
        virtual T area() const = 0;
        virtual operator double() const = 0;
        
        template <typename L>
        requires std::integral<L> || std::floating_point<L>
        friend std::ostream& operator<< (std::ostream &out, const Figure<L> &figure);

        template <typename L>
        requires std::integral<L> || std::floating_point<L>
        friend std::istream& operator>> (std::istream &in, Figure<L> &figure);
        
        virtual ~Figure() = default;
        
    protected:
        virtual std::ostream& print(std::ostream &out) const = 0;
        virtual std::istream& input(std::istream &in) = 0 ;
};

#include "../src/Figure.cpp"
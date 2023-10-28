#include <iostream>
#include "Vector.h"

class Figure
{
    public:
        virtual Point center() const = 0;
        virtual double area() const = 0;
        virtual operator double() const = 0;
        
        friend std::ostream& operator<< (std::ostream &out, const Figure &figure);
        friend std::istream& operator>> (std::istream &in, Figure &figure);
        
        virtual ~Figure() = default;
        
    protected:
        virtual std::ostream& print(std::ostream &out) const = 0;
        virtual std::istream& input(std::istream &in) = 0 ;
};
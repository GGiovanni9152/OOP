#include <iostream>
#include "Figure.h"

class Rectangle: public Figure
{
    public:
        Rectangle();
        Rectangle(const Point &a, const Point &b, const Point &c,  const Point &d);
        Rectangle(const Rectangle &other);
        Rectangle(const Rectangle &&other);

        Rectangle& operator= (const Rectangle &other);
        bool operator== (const Rectangle &other);

        Point center() const override;
        double area() const override;
        operator double() const override;

        ~Rectangle() = default;
        
    protected:
        std::ostream& print(std::ostream &out) const override;
        std::istream& input(std::istream &in) override;

        Point _a, _b, _c, _d;
        
};


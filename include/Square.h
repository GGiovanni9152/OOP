#include "Rectangle.h"

class Square final: public Rectangle
{
    public:
        Square() : Rectangle() {}
        Square(const Point& a, const Point& b, const Point &c, const Point& d);

        std::ostream& print(std::ostream &out) const override;

        ~Square() = default;
};
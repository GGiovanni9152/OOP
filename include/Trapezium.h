#include "Figure.h"

class Trapezium final: public Figure
{
    public:
        Trapezium();
        Trapezium(const Point &a, const Point &b, const Point &c, const Point &d);
        Trapezium(const Trapezium &other);
        Trapezium(const Trapezium &&other);

        Trapezium& operator= (const Trapezium &other);
        bool operator== (const Trapezium &other);
        
        Point center() const override;
        double area() const override;
        operator double() const override;

        ~Trapezium() = default;

    private:
        std::ostream& print(std::ostream &out) const override;
        std::istream& input(std::istream &in) override;

        Point _a, _b, _c, _d;
};
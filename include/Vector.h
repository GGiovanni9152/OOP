#include <iostream>

#include "Point.h"

class Vector
{
    public:
        Vector();
        Vector(double x, double y);
        Vector(const Point &begin, const Point &end);
        Vector(const Vector &other);

        double operator* (const Vector &other);
        Vector operator+ (const Vector &other);
        Vector operator- (const Vector &other);
        Vector operator= (const Vector &other);

        double X() const;
        double Y() const;
        double length();

    private:
        double _x, _y;
};

bool isParallel(const Vector &first, const Vector &second);
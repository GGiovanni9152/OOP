#include <iostream>

class Point
{
    public:
        Point();
        Point(double x, double y);
        Point(const Point &other);
        Point(const Point &&other) noexcept;

        double X() const;
        double Y() const;
       
        Point operator=(const Point &other);
        bool operator==(const Point &other) const;
        Point operator+ (const Point &other) const;
        Point operator/ (const double &a) const;

        friend std::ostream& operator<<(std::ostream &out, const Point &point);
        friend std::istream& operator>>(std::istream& in, Point &point);
    
    private:
        double _x;
        double _y;
};
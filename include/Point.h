#pragma once
#include <iostream>
#include <concepts>


template <typename T>
requires std::integral<T> || std::floating_point<T>
class Point
{
    public:
        Point();
        Point(T x, T y);
        Point(const Point &other);
        Point(const Point &&other) noexcept;

        T X() const;
        T Y() const;
       
        Point operator=(const Point &other);
        bool operator==(const Point &other) const;
        Point operator+ (const Point &other) const;
        Point operator/ (const T &a) const;

        template <typename L>
        requires std::integral<L> || std::floating_point<L>
        friend std::ostream& operator<<(std::ostream &out, const Point<L> &point);
        template <typename L>
        requires std::integral<L> || std::floating_point<L>
        friend std::istream& operator>>(std::istream& in, Point<L> &point);
    
    private:
        T _x;
        T _y;
    
};

#include "../src/Point.cpp"
#include <iostream>
#include "include/Point.h"
#include "include/Vector.h"
#include "include/Figure.h"
#include "include/Rectangle.h"
#include "include/Square.h"
#include "include/Trapezium.h"
#include "include/Din_Array.h"

int main()
{   
    Point <double> a(3., 3.); //Trapezium
    Point <double> b(4., 1.);
    Point <double> c(1., 1.);
    Point <double> d(2., 3.);

    Point <double> e(1., 1.); //Square
    Point <double> f(1., 2.);
    Point <double> g(2., 2.);
    Point <double> h(2., 1.);

    Point <double> x(1., 2.); //Rectangle
    Point <double> y(3., 2.);
    Point <double> z(3., 1.);
    Point <double> s(1., 1.);

    //Trapezium <double> trapecia(a, b, c, d);
    //Rectangle <double> rec;
    //Square <double> sqr;

    Array<std::shared_ptr<Figure<double>>> array {
                                            std::make_shared <Trapezium <double>>(a, b, c, d),
                                            std::make_shared <Rectangle <double>> (x, y, z, s),
                                            std::make_shared <Square <double>> (e, f, g, h)

    };
    
    array.print();
    //array.remove_element(0);
    //array.print();
    std::cout << array.element_area(0);
    //array.print_centers();
    //std::cout << array.element_center(1);
    //std::cout << array.print();
    //std::cout<< array[0] -> area();
    //std::cout << trapecia.center();

    return 0;
}
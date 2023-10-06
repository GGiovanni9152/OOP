#include <iostream>
#include "include/Four.h"

int main()
{
    Four a{'1','2','3'};
    Four b{'1','2','3'};
    Four d{'1','2'};
    Four e{'2','0','1'};
    Four f;
    Four c;
    Four g;
    f = (b + b);
    std::cin >> c;
    /*f.print(std::cout);
    std::cout << '\n';
    bool tet = (c < d);
    std::cout << tet << '\n';
    c.read_from_file("input.txt");
    tet = (e == (d + b));
    std::cout << tet << '\n';
    c += b;
    d += b;
    d.print(std::cout);
    std::cout << '\n';
    c.save_to_file("output.txt");
    f -= c;
    f.print(std::cout);
    std::cout << '\n';
    Four g;
    g.read_from_file("output.txt");
    g.print(std::cout);
    std::cout << '\n';
    */
    e.save_to_file("output.txt");
    g.read_from_file("output.txt");
    g.print(std::cout);
    std::cout << '\n';
    c.print(std::cout);
    std::cout << '\n';
    return 0;
}

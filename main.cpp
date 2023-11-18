#include <iostream>
#include "List.h"
#include "Allocator.h"
#include "Factorial.h"

int main()
{
    List<int, mai::Allocator<int>> list;
    List<int, mai::Allocator<int>> list1;

    int x1 = 1, x2 = 2, x3 = 3, x4 = 4, x5 = 5;
    list.push_back(x1);
    list.push_back(x2);
    list.push_back(x3);
    list.push_back(x4);
    auto val = list.insert(++++list.begin(), x5);
    list.erase(++++list.begin());
    for(auto i:list ) std::cout << i << std::endl;
    std::cout << list[2]  << ' ' << list[3] << '\n' << '\n' ;
    //std::cout << list.size() << '\n';
    //std::cout << *(list.cbegin()) << '\n';
    //std::cout << *(list.cend());

    mapa map;
    fill_map(map, 10);

    int summ = 0;

    for (auto elem : map)
    {
        summ += elem.second;
    }

    std::cout << list.front() << ' ' << list.back() << ' ' << list1.empty();
    //std::cout << summ;

    return 0;
}
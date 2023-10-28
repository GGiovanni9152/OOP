#include "Array.h"

double array_area(const std::vector<Figure*> &array)
{
    double summa = 0;
    int n = array.size();
    for (int i = 0; i < n; ++i)
    {
        summa += array[i]->area();
    }
    return summa;
}

double index_area(const std::vector<Figure*> &array, int index)
{
    return array[index] -> area();
}

void array_centers(const std::vector<Figure*> &array)
{
    int n = array.size();
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] -> center() << '\n';
    }
}

void delete_element(std::vector<Figure*> &array, int index)
{
    auto iter = array.begin();
    std::advance(iter, index);
    array.erase(iter);
}
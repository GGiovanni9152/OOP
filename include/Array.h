#include <iostream>
#include <vector>
#include <iterator>
#include "include/Square.h"

double array_area(const std::vector<Figure*> &array);
double index_area(const std::vector<Figure*> &array, int index);
void array_centers(const std::vector<Figure*> &array);
void delete_element(std::vector<Figure*> &array, int index);

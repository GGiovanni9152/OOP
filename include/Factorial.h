#pragma once
#include <iostream>
#include <map>
#include <utility>
#include "Allocator.h"

using mapa = std::map<int64_t, int64_t, std::less<int64_t>, mai::Allocator<std::pair<const int64_t, int64_t>>>;

int64_t factorial(int64_t n)
{
    if (n == 0)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

void fill_map(mapa &map, int n)
{
    for (int64_t i = 0; i < n; ++i)
    {
        map.insert(std::pair<int64_t, int64_t>(i, factorial(i)));
    }
}
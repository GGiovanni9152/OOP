#pragma once
#include "factory.h"
#include <cstring>

void save(const set_t &array, const std::string &filename);

set_t load(const std::string &filename);
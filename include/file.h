#pragma once
#include "factory.h"
#include <cstring>

void save(const set_npc &array, const std::string &filename);

set_npc load(const std::string &filename);
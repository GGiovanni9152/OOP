#pragma once

#include "npc.h"
#include "knight.h"
#include "pegas.h"
#include "belka.h"

class Factory
{
    public:
        std::shared_ptr<NPC> factory(std::istream &is);

        std::shared_ptr<NPC> factory(NpcType type, int x, int y, std::string name);

};
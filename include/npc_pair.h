#pragma once
#include "npc.h"

class PairNPC
{
    public:
        std::shared_ptr<NPC> first;
        std::shared_ptr<NPC> second;
        virtual int accept(Visitor& visitor);
};
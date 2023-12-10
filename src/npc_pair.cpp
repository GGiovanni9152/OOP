#include "../include/npc_pair.h"

int PairNPC::accept(Visitor& visitor)
{
    return visitor.visit(*this);
}
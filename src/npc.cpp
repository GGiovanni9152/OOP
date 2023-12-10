#include "../include/npc.h"

NPC::NPC(NpcType t, int _x, int _y, std::string _name) : type(t), x(_x), y(_y), name(_name) {}
NPC::NPC(NpcType t, std::istream &is) : type(t)
{
    is >> x;
    is >> y;
    is >> name;
}

void NPC::subscribe(std::shared_ptr<IFightObserver> observer)
{
    observers.push_back(observer);
}

void NPC::fight_notify(const std::shared_ptr<NPC> defender, bool win)
{
    for (auto &elem : observers)
    {
        elem -> on_fight(shared_from_this(), defender, win);
    }
}

bool NPC::is_close(const std::shared_ptr<NPC> &other, size_t distance) const
{
    /*if (std::pow(x - other -> x, 2) + std::pow(y - other -> y, 2) <= std::pow(distance, 2))
    {
        return true;
    }

    return false;*/

    return (std::pow(x - other -> x, 2) + std::pow(y - other -> y, 2)) <= std::pow(distance, 2);
}

void NPC::save(std::ostream &os)
{
    os << x << std::endl;
    os << y << std::endl;
    os << name << std::endl;
}

std::ostream &operator<<(std::ostream &os, NPC &npc)
{
    os << "name: " << npc.name << ", " <<"{x: " << npc.x << ", y:" << npc.y << "}\n";
    return os;
} 


#include "../include/knight.h"

Knight::Knight(int x, int y, std::string name) : NPC(Knight_Type, x, y, name) {}
Knight::Knight(std::istream &is) : NPC(Knight_Type, is) {}

void Knight::print()
{
    std::cout << *this;
}

void Knight::save(std::ostream &os)
{
    os << Knight_Type << std::endl;
    NPC::save(os);
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC*>(&knight) << std::endl;
    return os;
}

int Knight::accept(Visitor& visitor)
{
    return visitor.visit(*this);
}
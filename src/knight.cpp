#include "knight.h"
#include "belka.h"
#include "pegas.h"

Knight::Knight(int x, int y) : NPC(Knight_Type, x, y, 10, 30) {}
Knight::Knight(std::istream &is) : NPC(Knight_Type, is, 10, 30) {}

void Knight::print()
{
    std::cout << *this;
}

bool Knight::accept(std::shared_ptr<NPC> visitor)
{
    return visitor -> fight(std::shared_ptr<Knight>(this, [](Knight*){}));
}

void Knight::save(std::ostream &os)
{
    os << Knight_Type << std::endl;
    NPC::save(os);
}

bool Knight::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Knight::fight(std::shared_ptr<Belka> other)
{
    fight_notify(other, true);
    return true;
}

bool Knight::fight(std::shared_ptr<Pegas> other)
{
    fight_notify(other, false);
    return false;
}

std::ostream &operator<<(std::ostream &os, Knight &knight)
{
    os << "knight: " << *static_cast<NPC*>(&knight) << std::endl;
    return os;
}

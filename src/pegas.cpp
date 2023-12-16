#include "knight.h"
#include "belka.h"
#include "pegas.h"

Pegas::Pegas(int x, int y) : NPC(Pegas_Type, x, y, 10, 30) {}
Pegas::Pegas(std::istream &is) : NPC(Pegas_Type, is, 10, 30) {}

bool Pegas::accept(std::shared_ptr<NPC> visitor)
{
    return visitor -> fight(std::shared_ptr<Pegas>(this, [](Pegas*){}));
}

void Pegas::print()
{
    std::cout << *this;
}

void Pegas::save(std::ostream &os)
{
    os << Pegas_Type << std::endl;
    NPC::save(os);
}

std::ostream &operator<< (std::ostream &os, Pegas &pegas)
{
    os << "pegas: " << *static_cast<NPC*>(&pegas) << std::endl;
    return os;
}

bool Pegas::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Pegas::fight(std::shared_ptr<Belka> other)
{
    fight_notify(other, false);
    return false;
}

bool Pegas::fight(std::shared_ptr<Pegas> other)
{
    fight_notify(other, false);
    return false;
}
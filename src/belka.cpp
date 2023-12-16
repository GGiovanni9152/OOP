#include "knight.h"
#include "belka.h"
#include "pegas.h"

Belka::Belka(int x, int y) : NPC(Belka_Type, x, y, 5, 5){}
Belka::Belka(std::istream & is) : NPC(Belka_Type, is, 5, 5) {}

void Belka::print()
{
    std::cout << *this;
}

void Belka::save(std::ostream &os)
{
    os << Belka_Type << std::endl;
    NPC::save(os);
}

bool Belka::accept(std::shared_ptr<NPC> visitor)
{
    return visitor -> fight(std::shared_ptr<Belka>(this, [](Belka*){}));
}

bool Belka::fight(std::shared_ptr<Knight> other)
{
    fight_notify(other, false);
    return false;
}

bool Belka::fight(std::shared_ptr<Belka> other)
{
    fight_notify(other, false);
    return false;
}

bool Belka::fight(std::shared_ptr<Pegas> other)
{
    fight_notify(other, true);
    return true;
}

std::ostream &operator<< (std::ostream &os, Belka &belka)
{
    os << "belka: " << *static_cast<NPC*> (&belka) << std::endl;
    return os;
}

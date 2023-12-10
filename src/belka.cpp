#include "../include/belka.h"

Belka::Belka(int x, int y, std::string name) : NPC(Belka_Type, x, y, name){}
Belka::Belka(std::istream & is) : NPC(Belka_Type, is) {}

void Belka::print()
{
    std::cout << *this;
}

void Belka::save(std::ostream &os)
{
    os << Belka_Type << std::endl;
    NPC::save(os);
}

std::ostream &operator<< (std::ostream &os, Belka &belka)
{
    os << "belka: " << *static_cast<NPC*> (&belka) << std::endl;
    return os;
}

int Belka::accept(Visitor& visitor)
{
    return visitor.visit(*this);
}
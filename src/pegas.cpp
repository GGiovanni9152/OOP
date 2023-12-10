#include "../include/pegas.h"

Pegas::Pegas(int x, int y, std::string name) : NPC(Pegas_Type, x, y, name) {}
Pegas::Pegas(std::istream &is) : NPC(Pegas_Type, is) {}

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

int Pegas::accept(Visitor& visitor)
{
    return visitor.visit(*this);
}
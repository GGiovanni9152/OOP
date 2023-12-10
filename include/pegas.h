#pragma once
#include "npc.h"

class Pegas : public NPC
{
    public:
        Pegas(int x, int y, std::string name);
        Pegas(std::istream &is);

        void print() override;
        void save(std::ostream &os) override;
        virtual int accept(Visitor& visitor) override;
        
        friend std::ostream &operator<<(std::ostream &os, Pegas &pegas);
};
#pragma once
#include "npc.h"


class Pegas : public NPC
{
    public:
        Pegas(int x, int y);
        Pegas(std::istream &is);

        void print() override;
        void save(std::ostream &os) override;

        bool fight(std::shared_ptr<Knight> other) override;
        bool fight(std::shared_ptr<Belka> other) override;
        bool fight(std::shared_ptr<Pegas> other) override;

        bool accept(std::shared_ptr<NPC> visitor) override;
        
        friend std::ostream &operator<<(std::ostream &os, Pegas &pegas);
};
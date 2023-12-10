#pragma once
#include "npc.h"

class Belka : public NPC
{
    public:
        Belka(int x, int y, std::string name);
        Belka(std::istream &is);

        void print() override;


        void save(std::ostream &os) override;
        virtual int accept(Visitor& visitor) override;

        friend std::ostream& operator<< (std::ostream&os, Belka &belka);

};
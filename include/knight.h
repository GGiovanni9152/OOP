#pragma once
#include "npc.h"

class Knight : public NPC
{
    public:
        Knight(int x, int y, std::string name);
        Knight(std::istream &is);

        void print() override;
        void save(std::ostream &os) override;

        virtual int accept(Visitor& visitor) override;

        friend std::ostream& operator<<(std::ostream &os, Knight &knight);
};
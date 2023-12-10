#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <memory>
#include <set>
#include <vector>

class NPC;
class Knight;
class Belka;
class Pegas;
class Visitor;
class PairNPC;

using set_t = std::set<std::shared_ptr<NPC>>;

enum NpcType
{
    Unknown = 0,
    Knight_Type = 1,
    Belka_Type = 2,
    Pegas_Type = 3
};

class IFightObserver
{
    public:
        virtual void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) = 0;
};

class NPC : public std::enable_shared_from_this<NPC>
{
    public:
        NpcType type;
        
        int x{0};
        int y{0};

        std::string name;

        std::vector<std::shared_ptr<IFightObserver>> observers;

        NPC(NpcType t, int _x, int _y, std::string _name);
        NPC(NpcType t, std::istream &is);

        void subscribe(std::shared_ptr<IFightObserver> observer);
        void fight_notify(const std::shared_ptr<NPC> defender, bool win);
        virtual bool is_close(const std::shared_ptr<NPC> &other, size_t distance) const;

        virtual void print() = 0;

        virtual void save(std::ostream &os);

        friend std::ostream& operator<< (std::ostream &os, NPC &nps);

        virtual int accept(Visitor& visitor) = 0;
};

class Visitor
{
    public:
        virtual int visit(Knight& element) = 0;
        virtual int visit(Belka& element) = 0;
        virtual int visit(Pegas& element) = 0;
        virtual int visit(PairNPC& element) = 0;
};

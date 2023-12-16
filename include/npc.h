#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <memory>
#include <set>
#include <vector>
#include <shared_mutex>
#include <random>
#include <mutex>

class NPC;
class Knight;
class Belka;
class Pegas;

using set_npc = std::set<std::shared_ptr<NPC>>;

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
    private:
        mutable std::mutex mtx;

        NpcType type;
        
        int x{0};
        int y{0};

        bool alive{true};
        
        //std::string name;

        std::vector<std::shared_ptr<IFightObserver>> observers;

    public:

        NPC(NpcType t, int _x, int _y, int _fight_dist, int _move_dist);
        NPC(NpcType t, std::istream &is, int _fight_dist, int _move_dist);

        void subscribe(std::shared_ptr<IFightObserver> observer);
        void fight_notify(const std::shared_ptr<NPC> defender, bool win);
        virtual bool is_close(const std::shared_ptr<NPC> &other) const;

        virtual bool accept(std::shared_ptr<NPC> visitor) = 0;

        virtual bool fight(std::shared_ptr<Knight> other) = 0;
        virtual bool fight(std::shared_ptr<Belka> other) = 0;
        virtual bool fight(std::shared_ptr<Pegas> other) = 0;

        virtual void print() = 0;
        std::pair<int, int> position();
        NpcType get_type();

        virtual void save(std::ostream &os);

        friend std::ostream& operator<< (std::ostream &os, NPC &nps);

        void move(int shift_x, int shift_y, int max_x, int max_y);

        bool is_alive();
        void must_die();

    protected:
        int fight_dist = 0;
        int move_dist = 0;
};


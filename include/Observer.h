#pragma once
#include "npc.h"
#include "knight.h"
#include "pegas.h"
#include "belka.h"
#include "fstream"

class TextObserver : public IFightObserver
{
    private:
        TextObserver(){};

    public:
        static std::shared_ptr<IFightObserver> get();
        void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};

class FileObserver : public IFightObserver
{
    private:
        FileObserver() {};

    public:
        static std::shared_ptr<IFightObserver> get();
        void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override;
};

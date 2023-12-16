#pragma once
#include "npc.h"
#include "knight.h"
#include "pegas.h"
#include "belka.h"
#include <fstream>

std::mutex print_mutex;

class TextObserver : public IFightObserver
{
    private:
        TextObserver(){};

    public:
        static std::shared_ptr<IFightObserver> get()
        {
            static TextObserver instance;
            return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
        }
        void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
        {
            if (win)
            {
                std::lock_guard<std::mutex> lck(print_mutex);
                std::cout << std::endl
                            << "Murder --------" << std::endl;
                attacker->print();
                defender->print();
            }
        }
};

class FileObserver : public IFightObserver
{
    private:
        FileObserver() {};

    public:
        static std::shared_ptr<IFightObserver> get()
        {
        static FileObserver instance;
        return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
        }

        void on_fight(const std::shared_ptr<NPC> attacker, const std::shared_ptr<NPC> defender, bool win) override
        {
            std::ofstream fs;
            fs.open("log.txt", std::ios::app);

            if (win)
            {
                std::lock_guard<std::mutex> lck(print_mutex);
                fs << std::endl << "Murder --------" << std::endl;
                fs << *attacker << std::endl;
                fs << *defender << std::endl;
            }

            fs.flush();

            fs.close();
        }
};

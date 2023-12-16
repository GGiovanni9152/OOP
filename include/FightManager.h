#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include "npc.h"
#include <queue>
#include <shared_mutex>
#include <chrono>
#include <thread>
#include <optional>

using namespace std::chrono_literals;

struct print : std::stringstream
{
    ~print()
    {
        static std::mutex mtx;
        std::lock_guard<std::mutex> lck(print_mutex);
        std::cout << this -> str();
        std::cout.flush();
    }
};


struct FightEvent
{
    std::shared_ptr<NPC> attacker;
    std::shared_ptr<NPC> defender;
};


class FightManager
{
    private:
        std::queue<FightEvent> events;
        std::shared_mutex mtx;

        FightManager() {}
    
    public:
        static FightManager &get()
        {
            static FightManager instance;
            return instance;
        }

        void add_event(FightEvent &&event)
        {
            std::lock_guard<std::shared_mutex> lock(mtx);
            events.push(event);
        }

        void operator()(bool &flag)
        {
            while (!flag)
            {
                {
                    std::optional<FightEvent> event;

                    {
                        std::lock_guard<std::shared_mutex> lock(mtx);

                        if (!events.empty())
                        {
                            event = events.back();
                            events.pop();
                        }
                    }

                    if (event)
                    {
                        try
                        {
                            if (event -> attacker -> is_alive())
                                if (event -> defender -> is_alive())
                                    if (event -> defender -> accept(event -> attacker))
                                    {
                                        event -> defender -> must_die();
                                    }
                        }

                        catch (...)
                        {
                            std::lock_guard<std::shared_mutex> lock(mtx);
                            events.push(*event);
                        }
                    }
                    else
                    {
                        std::this_thread::sleep_for(100ms);
                    }
                }
            }
        }

};




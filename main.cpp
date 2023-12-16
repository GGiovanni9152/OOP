#include "knight.h"
#include "belka.h"
#include "pegas.h"
#include "factory.h"
#include "FightManager.h"
#include <array>


std::ostream& operator<<(std::ostream &os, const set_npc &array)
{
    for (auto &elem : array)
    {
        elem -> print();
    }

    return os;
}


int main()
{
    set_npc array;

    const int MAX_X = 100;
    const int MAX_Y = 100;

    Factory factor;


    for (int i = 0; i < 50; ++i)
    {
        array.insert(factor.factory(NpcType(std::rand() % 3 + 1), std::rand() % MAX_X,
                                                                  std::rand() % MAX_Y));
    }

    bool flag = false;

    std::thread fight_thread(std::ref(FightManager::get()), std::ref(flag));

    std::thread move_thread([&array, MAX_X, MAX_Y, &flag]()
    {
        while (!flag)
        {
            for (std::shared_ptr<NPC> npc : array)
            {
                if (npc -> is_alive())
                {
                    int shift_x = std::rand() % 20 - 10;
                    int shift_y = std::rand() % 20 - 10;
                    npc -> move(shift_x, shift_y, MAX_X, MAX_Y);
                }
            }
            
            for (std::shared_ptr<NPC> attacker : array)
                for (std::shared_ptr<NPC> defender : array)
                    if (attacker -> is_alive() && defender -> is_alive())
                        if (attacker -> is_close(defender))
                        {
                            FightManager::get().add_event({attacker, defender});
                        }
            std::this_thread::sleep_for(1s);
        }
    });

    std::thread finish_thread([&]()
    {
        std::this_thread::sleep_for(10s);
        flag = true;
        std::lock_guard<std::mutex> lck(print_mutex);
        move_thread.join();
        fight_thread.join();
    });

    while (!flag)
    {
        const int grid = 20, step_x = MAX_X / grid, step_y = MAX_Y / grid;
        {
            std::array<char, grid * grid> fields{0};

            for (std::shared_ptr<NPC> npc : array)
            {
                auto [x, y] = npc -> position();
                int i = x / step_x;
                int j = y / step_y;

                if (npc -> is_alive())
                {
                    switch (npc -> get_type())
                    {
                        case Knight_Type:
                            fields[i + grid * j] = 'K';
                            break;
                        
                        case Belka_Type:
                            fields[i + grid * j] = 'B';
                            break;
                        
                        case Pegas_Type:
                            fields[i + grid * j] = 'P';
                            break;
                        
                        default:
                            break;
                    }
                }

                else
                {
                    fields[i + grid * j] = '.';
                }
            }

            std::lock_guard<std::mutex> lck(print_mutex);

            for (int j = 0; j < grid; ++j)
            {
                for (int i = 0; i < grid; ++i)
                {
                    char symbol = fields[i + j * grid];
                    
                    if (symbol == '.')
                    {
                        std::cout << "\u2715 ";
                    }

                    else if (symbol != 0)
                    {
                        std:: cout << symbol << ' ';
                    }

                    else
                    {
                        std::cout << "\u00B7 ";
                    }

                }

                std::cout << std::endl;

            }
            std::cout << std::endl;

            std::this_thread::sleep_for(1s);
        }
    };

    finish_thread.join();

    return 0;
}
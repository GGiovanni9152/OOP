#include "../include/fight.h"

set_t fight(const set_t &array, size_t distance)
{
    set_t dead_list;

    for (const auto &attacker : array)
    {
        for (const auto &defender : array)
        {
            if ((attacker != defender) && (attacker -> is_close(defender, distance)))
            {
                int success = 0;

                FightVisitor visitor;

                PairNPC fighters;
                fighters.first = attacker;
                fighters.second = defender;
                
                success = fighters.accept(visitor);

                if (success)
                {
                    dead_list.insert(defender);
                }

            }
        }
    }

    return dead_list;
}

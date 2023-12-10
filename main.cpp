#include "../include/knight.h"
#include "../include/belka.h"
#include "../include/pegas.h"
#include "../include/factory.h"
#include "../include/fight.h"

int main()
{
    set_t array;
    set_t dead;

    Factory factor;

    array.insert(factor.factory(NpcType(1), 1, 2, "Ara"));
    array.insert(factor.factory(NpcType(2), 3, 4, "Motya"));
    array.insert(factor.factory(NpcType(2), 5, 6, "Momtya"));
    
    dead = fight(array, 10);

    for (std::shared_ptr<NPC> elem : array)
    {
        std::cout << *elem;
    }

    std::cout << dead.size();

    return 0;
}
#include "../include/Visitor.h"

int FightVisitor::visit(Pegas& element)
{
    return 1;
}

int FightVisitor::visit(Belka& element)
{
    return 2;
}

int FightVisitor::visit(Knight& element)
{
    return 3;
}

int FightVisitor::visit(PairNPC& element)
{
    FightVisitor tmp;

    int result = element.first -> accept(tmp) - element.second -> accept(tmp);

    if (result == 1)
    {
        element.first -> fight_notify(element.second, true);
        return 1;
    }

    element.first -> fight_notify(element.second, false);
    return 0;
}
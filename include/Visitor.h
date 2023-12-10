#pragma once
#include "knight.h"
#include "pegas.h"
#include "belka.h"
#include "npc_pair.h"

class FightVisitor : public Visitor
{
    virtual int visit(Pegas& element) override;

    virtual int visit(Belka& element) override;

    virtual int visit(Knight& element) override;

    virtual int visit(PairNPC& element) override;

};
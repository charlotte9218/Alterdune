#ifndef BOSS_H
#define BOSS_H

#include "Monstre.h"

class Boss : public Monstre
{

public:
    Boss(string nom, int hpMax, int attaque, int defense, int mercyObjectif, vector<string> actions);
    int NbActionsAct() const override;
    Monstre *Clone() const override;
};

#endif
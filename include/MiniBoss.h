#ifndef MINIBOSS_H
#define MINIBOSS_H

#include "Monstre.h"

class MiniBoss : public Monstre
{

public:
    MiniBoss(string nom, int hpMax, int attaque, int defense, int mercyObjectif, vector<string> actions);
    int NbActionsAct() const override;
    Monstre *Clone() const override;
};

#endif
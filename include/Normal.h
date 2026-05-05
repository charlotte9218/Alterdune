#ifndef NORMAL_H
#define NORMAL_H

#include "Monstre.h"

class Normal : public Monstre
{

public:
    Normal(string nom, int hpMax, int attaque, int defense, int mercyObjectif, vector<string> actions);
    int NbActionsAct() const override;
    virtual Monstre *Clone() const override;
    string GetCategorie() const;
};

#endif
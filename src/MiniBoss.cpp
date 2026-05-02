#include "../include/MiniBoss.h"
using namespace std;

MiniBoss::MiniBoss(string nom, int HP_Max, int attaque, int defense, int mercyObjectif, vector<string> actions)
    : Monstre(nom, HP_Max, attaque, defense, mercyObjectif, actions)
{
}

int MiniBoss::NbActionsAct() const
{
    return 3;
}

Monstre *MiniBoss::Clone() const
{
    return new MiniBoss(*this);
}

string MiniBoss::GetCategorie() const
{
    return "MINIBOSS";
}

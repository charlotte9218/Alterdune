#include "../include/Boss.h"
using namespace std;

Boss::Boss(string nom, int HP_Max, int attaque, int defense, int mercyObjectif, vector<string> actions)
    : Monstre(nom, HP_Max, attaque, defense, mercyObjectif, actions)
{
}

int Boss::NbActionsAct() const
{
    return 4;
}
Monstre *Boss::Clone() const
{
    return new Boss(*this);
}
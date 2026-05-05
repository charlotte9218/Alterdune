#include "../include/Normal.h"
using namespace std;

Normal::Normal(string nom, int HP_Max, int attaque, int defense, int mercyObjectif, vector<string> actions)
    : Monstre(nom, HP_Max, attaque, defense, mercyObjectif, actions)
{
}

int Normal::NbActionsAct() const
{
    return 2;
}

Monstre *Normal::Clone() const
{
    return new Normal(*this);
}
string Normal::GetCategorie() const
{
    return "NORMAL";
}
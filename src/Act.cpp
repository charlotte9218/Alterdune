#include "../include/Act.h"
#include <iostream>
using namespace std;

Act::Act()
{
    id_Act = "";
    texte = "";
    impactMercy = 0;
}
Act::Act(string id_Act, string texte, int impactMercy)
{
    this->id_Act = id_Act;
    this->texte = texte;
    this->impactMercy = impactMercy;
}

string Act::GetId() const
{
    return id_Act;
}

string Act::GetTexte() const
{
    return texte;
}

int Act::GetImpactMercy() const
{
    return impactMercy;
}

void Act::Afficher() const
{
    cout << texte << endl;
}

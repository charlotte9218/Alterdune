#include "entite.h"

Entite::Entite()
{
    name = "";
    currentHP = 0;
    maxHP = 0;
    attack = 0;
    defense = 0;
}

Entite::Entite(string name, int maxHP, int attack, int defense)
{
    this->name = name;
    this->maxHP = maxHP;
    this->currentHP = maxHP;
    this->attack = attack;
    this->defense = defense;
}

void Entite::Damage(int degats)
{
    currentHP = currentHP - degats;

    if (currentHP < 0)
    {
        currentHP = 0;
    }
}
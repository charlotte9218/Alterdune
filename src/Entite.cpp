#include "../include/Entite.h"
#include <iostream>
using namespace std;

Entite::Entite(string nom, int HP_Max, int attaque, int defense)
{
    this->nom = nom;
    this->HP_Max = HP_Max;
    this->HP_Actuel = HP_Max;
    this->attaque = attaque;
    this->defense = defense;
}

bool Entite::estEnVie() const
{
    if (HP_Actuel > 0)
    {
        return true;
    }
    return false;
}

void Entite::subirDegats(int degats)
{
    HP_Actuel = HP_Actuel - degats;
    if (HP_Actuel < 0)
    {
        HP_Actuel = 0;
    }
}

int Entite::GetHPActuel() const
{
    return HP_Actuel;
}

int Entite::GetHPMax() const
{
    return HP_Max;
}

string Entite::GetNom() const
{
    return nom;
}

int Entite::GetAttaque() const
{
    return attaque;
}

void Entite::AugmenterAttaque(int valeur)
{
    attaque = attaque + valeur;
}

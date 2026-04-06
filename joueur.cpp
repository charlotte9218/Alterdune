#include "joueur.h"

Joueur::Joueur() : Entite()
{
    victoire = 0;
}

Joueur::Joueur(string name, int maxHP, int attack, int defense)
    : Entite(name, maxHP, attack, defense)
{
    victoire = 0;
}

void Joueur::Statistiques()
{
    cout << "Nom : " << name << endl;
    cout << "HP : " << currentHP << "/" << maxHP << endl;
    cout << "ATK : " << attack << endl;
    cout << "DEF : " << defense << endl;
    cout << "Victoires : " << victoire << endl;
}
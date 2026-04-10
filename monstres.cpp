#include "monstres.h"

Monstres::Monstres() : Entite()
{
    JaugeMercy = 0;
    MercyGoal = 100;
}

Monstres::Monstres(string name, int maxHP, int attack, int defense, int MercyGoal)
    : Entite(name, maxHP, attack, defense)
{
    JaugeMercy = 0;
    this->MercyGoal = MercyGoal;
}

void Monstres::Attaque(Joueur &j)
{
    cout << name << " attaque le joueur." << endl;
    j.Damage(attack);
}

void Monstres::Statistiques()
{
    cout << "Nom : " << name << endl;
    cout << "HP : " << currentHP << "/" << maxHP << endl;
    cout << "ATK : " << attack << endl;
    cout << "DEF : " << defense << endl;
    cout << "Mercy : " << JaugeMercy << "/" << MercyGoal << endl;
}

void Monstres::modifierMercy(int valeur) {
    JaugeMercy += valeur;
    if (JaugeMercy > MercyGoal) JaugeMercy = MercyGoal;
    if (JaugeMercy < 0) JaugeMercy = 0;
}
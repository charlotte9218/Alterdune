#ifndef ENTITE_H
#define ENTITE_H

#include <iostream>
#include <string>

using namespace std;

class Entite
{
protected:
    string name;
    int currentHP;
    int maxHP;
    int attack;
    int defense;

public:
    Entite();
    Entite(string name, int maxHP, int attack, int defense);

    void Damage(int degats);
    int getHP() const;
    void setHP(int hp);

    virtual void Statistiques() = 0;
};

#endif
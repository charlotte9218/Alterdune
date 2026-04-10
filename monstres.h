#ifndef MONSTRES_H
#define MONSTRES_H

#include <iostream>
#include "entite.h"
#include "joueur.h"

using namespace std;

class Monstres : public Entite
{
private:
    int JaugeMercy;
    int MercyGoal;

public:
    Monstres();
    Monstres(string name, int maxHP, int attack, int defense, int MercyGoal);

    void Attaque(Joueur &j);
    void Statistiques() override;
    int Degat();
};

#endif
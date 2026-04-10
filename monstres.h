#ifndef MONSTRES_H
#define MONSTRES_H

#include "entite.h"
#include "joueur.h"
#include <string>
#include <iostream>

class Monstres : public Entite
{
private:
    int JaugeMercy;
    int MercyGoal;

public:
    Monstres();
    Monstres(std::string name, int maxHP, int attack, int defense, int MercyGoal);

    void Attaque(Joueur &j);
    void Statistiques() override;

    void modifierMercy(int valeur);

    int getJaugeMercy() const { return JaugeMercy; }
    int getMercyGoal() const { return MercyGoal; }
};

#endif
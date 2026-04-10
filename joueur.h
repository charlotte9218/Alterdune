#ifndef JOUEUR_H
#define JOUEUR_H

#include "entite.h"

class Joueur : public Entite
{
private:
    int victoire;

public:
    Joueur();
    Joueur(string name, int maxHP, int attack, int defense);

    int getHP() const;
    void setHP(int hp);

    void Statistiques() override;
};

#endif
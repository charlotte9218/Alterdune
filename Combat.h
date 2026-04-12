#ifndef COMBAT_H
#define COMBAT_H

#include <iostream>
#include <vector>
#include "actions.cpp"
#include "actions.h"
#include <string>
#include "monstres.h"
#include "joueur.h"
using namespace std;

class Combat
{
private:
    Monstres *monstre;
    Joueur *joueur;
    int calculerDegat();
    void afficherMenu();
    void handleFight();
    void handleAct();
    void handleItem();
    bool handleMercy();

public:
    Combat(Monstres *m, Joueur *j);
    bool executeCombat();
};

#endif
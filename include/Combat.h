#ifndef COMBAT_H
#define COMBAT_H

#include "Joueur.h"
#include "Monstre.h"
#include "Act.h"
#include <map>

using namespace std;

class Combat
{
private:
    Joueur *joueur; // On utilise des pointeurs pour modifie l'objet et pas juste sa copie
    Monstre *monstre;
    map<string, Act> *catalogueAct;
    bool combatGagne;

public:
    Combat(Joueur *joueur, Monstre *monstre, map<string, Act> *catalogueAct);
    void Lancer();
    void AfficherMenu() const;
    void ActionFight();
    void ActionAct();
    void ActionItem();
    void ActionMercy();
    void TourMonstre();
};

#endif
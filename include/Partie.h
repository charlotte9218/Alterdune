#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.h"
#include "Monstre.h"
#include "Normal.h"
#include "MiniBoss.h"
#include "Boss.h"
#include "Act.h"
#include "Combat.h"

#include <vector>
#include <map>
#include <string>

using namespace std;

class Partie
{
private:
    Joueur *joueur;
    map<string, Act> catalogueAct;
    vector<Monstre *> listeMonstres;

public:
    Partie();
    ~Partie();

    void InitialiserCatalogueAct();
    vector<Item> ChargerItems();
    void ChargerMonstres();
    void InitialiserPartie();

    void AfficherMenu();
    void AfficherResume();
    void LancerJeu();
    void LancerCombat();
    bool FinPartie() const;
    void AfficherFin();
};

#endif
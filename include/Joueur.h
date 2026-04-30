#ifndef JOUEUR_H
#define JOUEUR_H
#include <string>
#include "Entite.h"
#include "Item.h"
#include <vector>

using namespace std;
class Joueur : public Entite
{
private:
    int nbVictoires;
    vector<Item> inventaire;
    int nbMonstreTues;
    int nbMonstresEpargnes;

public:
    Joueur(string nom, int HP_Max, int attaque, int defense, vector<Item> inventaire);
    int GetNbMonstreTues() const;
    int GetNbMonstresEpargnes() const;
    void afficherStatistiques() const override;
    void AfficherInventaire() const;
    bool UtiliserItem(int index);
    void ajouterVictoire();
    void incrementerTue();
    void incrementerEpargner();
    bool aGagne() const;
};
#endif

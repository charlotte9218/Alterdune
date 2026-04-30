#ifndef MONSTRE_H
#define MONSTRE_H

#include "Entite.h"
#include <vector>
#include <string>
using namespace std;

class Monstre : public Entite
{
protected:
    int mercy;
    int mercyObjectif;
    vector<string> actionsDisponibles;

public:
    Monstre(string nom, int HP_Max, int attaque, int defense, int mercyObjectif, vector<string> actions);
    virtual Monstre *Clone() const = 0;
    void modifierMercy(int valeur);
    bool peutEtreEpargner() const;
    void afficherStatistiques() const override;
    virtual int NbActionsAct() const = 0;
    vector<string> GetActions() const;
};
#endif
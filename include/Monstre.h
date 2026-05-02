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
    string resultat;

public:
    Monstre(string nom, int HP_Max, int attaque, int defense, int mercyObjectif, vector<string> actions);
    string getNom() const { return nom; }
    virtual Monstre *Clone() const = 0;
    int GetMercy();
    int GetMercyObjectif();
    void setResultat(string r);
    string getResultat() const;
    void modifierMercy(int valeur);
    bool peutEtreEpargner() const;
    void afficherStatistiques() const override;
    virtual int NbActionsAct() const = 0;
    vector<string> GetActions() const;
    virtual string GetCategorie() const = 0;
};
#endif
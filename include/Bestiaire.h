#ifndef BESTIAIRES_H
#define BESTIAIRES_H

#include <vector>
#include <string>
#include "Monstre.h"

using namespace std;

class Bestiaires
{
private:
    vector<Monstre *> MonstresVaincus;
    int NbVaincus;

public:
    Bestiaires();

    void ajouterMonstre(Monstre *m);
    bool dejaVaincu(const string &nom) const;
    Monstre *chercherMonstre(const string &nom);

    int getNbVaincus() const;
    const vector<Monstre *> &getMonstres() const;

    void AffichageB() const;
    void AffichageResume() const;
};

#endif
#ifndef BESTIAIRES_H
#define BESTIAIRES_H

#include <vector>
#include "monstres.h"

using namespace std;

class Bestiaires
{
private:

    vector<Monstres> MonstresVaincus;
    int NbVaincus;

public:

    Bestiaires();

    void ajouterMonstre(Monstres m);

    void AffichageB();

};

#endif
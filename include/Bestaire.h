#ifndef BESTIAIRE_H
#define BESTIAIRE_H

#include "Monstre.h"
#include <vector>
#include <string>
using namespace std;

class Bestiaire
{
private:
    vector<Monstre*> monstresVaincus;

public:
    Bestiaire();
    ~Bestiaire();

    void AjouterMonstre(const Monstre* m);
    bool DejaEnregistre(const string& nom) const;
    void Afficher() const;
};

#endif
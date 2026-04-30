#ifndef ENTITE_H
#define ENTITE_H
#include <string>

using namespace std;

class Entite
{
protected:
    string nom;
    int HP_Actuel;
    int HP_Max;
    int attaque;
    int defense;

public:
    Entite(string nom, int HP_MAx, int attaque, int defense);
    bool estEnVie() const;
    void subirDegats(int degats);
    int GetHPActuel() const;
    int GetHPMax() const;
    string GetNom() const;
    virtual void afficherStatistiques() const = 0;
};
#endif
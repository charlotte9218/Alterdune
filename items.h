#ifndef ITEMS_H
#define ITEMS_H

#include <string>

using namespace std;

class Joueur;

enum itemType
{
    HEAL
};

class Items
{
private:
    string nom;
    itemType Type;
    int quantiteDispo;
    int Valeur;

public:
    Items();
    Items(string nom, itemType Type, int quantiteDispo, int Valeur);

    string getNom();
    int getValeur();
    int getQuantite();

    bool Utiliser(Joueur &joueur);
    void Afficher();
};

#endif
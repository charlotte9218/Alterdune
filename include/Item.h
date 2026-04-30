#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item
{
private:
    string nom;
    string type;
    int valeur;
    int quantite;

public:
    Item(string nom, string type, int valeur, int quantite);
    string GetNom() const;
    string GetType() const;
    int GetValeur() const;
    int GetQuantite() const;

    bool EstDisponible() const;
    bool Utiliser();
    void AfficherDescription() const;
};
#endif

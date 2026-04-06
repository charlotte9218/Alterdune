#include "items.h"

Items::Items()
{
    nom = "";
    Type = HEAL;
    quantiteDispo = 0;
    Valeur = 0;
}

Items::Items(string nom, itemType Type, int quantiteDispo, int Valeur)
{
    this->nom = nom;
    this->Type = Type;
    this->quantiteDispo = quantiteDispo;
    this->Valeur = Valeur;
}
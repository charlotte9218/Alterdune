#include "items.h"
#include <iostream>
#include "joueur.h"

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

string Items::getNom()
{
    return nom;
}

int Items::getValeur()
{
    return Valeur;
}

int Items::getQuantite()
{
    return quantiteDispo;
}

bool Items::Utiliser(Joueur &joueur)
{
    if (quantiteDispo > 0)
    {
        quantiteDispo--;

        if (Type == HEAL)
        {
            joueur.setHP(joueur.getHP() + Valeur);
        }

        return true;
    }

    return false;
}

void Items::Afficher()
{
    if (Type == HEAL)
    {
        cout << "soigne " << Valeur << " HP";
    }
}
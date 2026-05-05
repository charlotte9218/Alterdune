#include "../include/Item.h"
#include <iostream>
using namespace std;

Item::Item(string nom, string type, int valeur, int quantite)
{
    this->nom = nom;
    this->type = type;
    this->valeur = valeur;
    this->quantite = quantite;
}

string Item::GetNom() const
{
    return nom;
}

string Item::GetType() const
{
    return type;
}

int Item::GetValeur() const
{
    return valeur;
}

int Item::GetQuantite() const
{
    return quantite;
}

bool Item::EstDisponible() const
{
    if (quantite > 0)
    {
        return true;
    }
    return false;
}

bool Item::Utiliser()
{
    if (quantite > 0)
    {
        quantite--;
        return true;
    }
    return false;
}

void Item::AfficherDescription() const
{
    if (type == "HEAL")
    {
        cout << nom << " soigne " << valeur << " HP. Quantite : " << quantite;
    }
    else if (type == "ATTACK")
    {
        cout << nom << " augmente l'attaque de " << valeur << ". Quantite : " << quantite;
    }
    else
    {
        cout << nom << " type inconnu : " << type << ". Quantite : " << quantite;
    }
}
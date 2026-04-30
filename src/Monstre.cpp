#include "../include/Monstre.h"
#include <iostream>
using namespace std;

Monstre::Monstre(string nom, int HP_Max, int attaque, int defense, int mercyObjectif, vector<string> actions) : Entite(nom, HP_Max, attaque, defense)
{
    this->mercy = 0;
    this->mercyObjectif = mercyObjectif;
    this->actionsDisponibles = actions;
}

void Monstre::modifierMercy(int valeur)
{
    mercy += valeur;
    if (mercy < 0)
    {
        mercy = 0;
    }
    if (mercyObjectif < mercy)
    {
        mercy = mercyObjectif;
    }
}

bool Monstre::peutEtreEpargner() const
{
    if (mercy >= mercyObjectif)
    {
        return true;
    }
    return false;
}

void Monstre::afficherStatistiques() const
{
    cout << "nom: " << nom << "\n"
         << "HP_Actuel: " << HP_Actuel << "\n"
         << "HP_Max: " << HP_Max << "\n"
         << "attaque: " << attaque << "\n"
         << "defense: " << defense << "\n"
         << "mercy/mercyObjectif: " << mercy << " / " << mercyObjectif << endl;
}

vector<string> Monstre::GetActions() const
{
    return actionsDisponibles;
}
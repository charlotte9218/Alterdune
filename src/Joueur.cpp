#include "../include/Joueur.h"
#include <iostream>
using namespace std;

Joueur::Joueur(string nom, int HP_Max, int attaque, int defense, vector<Item> inventaire)
    : Entite(nom, HP_Max, attaque, defense)
{
    this->inventaire = inventaire;
    this->nbVictoires = 0;
    this->nbMonstreTues = 0;
    this->nbMonstresEpargnes = 0;
}
int Joueur::GetNbMonstreTues() const
{
    return nbMonstreTues;
}

int Joueur::GetNbMonstresEpargnes() const
{
    return nbMonstresEpargnes;
}
void Joueur::afficherStatistiques() const
{
    cout << "Nom: " << nom << endl;
    cout << "HP: " << HP_Actuel << " / " << HP_Max << endl;
    cout << "Attaque" << attaque << endl;
    cout << "Victoires: " << nbVictoires << endl;
    cout << "Monstres tues: " << nbMonstreTues << endl;
    cout << "Monstres epargnes: " << nbMonstresEpargnes << endl;
}

void Joueur::AfficherInventaire() const
{
     for (int i = 0; i < inventaire.size(); i++)
    {
        cout << i << " : ";
        inventaire[i].AfficherDescription();
        cout << endl;
    }
}

bool Joueur::UtiliserItem(int index)
{
    if (index < 0 || index >= inventaire.size())
    {
        return false;
    }

    if (!inventaire[index].EstDisponible())
    {
        return false;
    }

    string type = inventaire[index].GetType();
    int valeur = inventaire[index].GetValeur();

    inventaire[index].Utiliser();

    if (type == "HEAL")
    {
        cout << "HP avant item : " << HP_Actuel << endl;

        HP_Actuel += valeur;

        if (HP_Actuel > HP_Max)
        {
            HP_Actuel = HP_Max;
        }

        cout << "Vous recuperez " << valeur << " HP." << endl;
        cout << "HP apres item : " << HP_Actuel << endl;

        return true;
    }
    else if (type == "ATTACK")
    {
        cout << "Attaque avant item : " << attaque << endl;

        AugmenterAttaque(valeur);

        cout << "Votre attaque augmente de " << valeur << " points." << endl;
        cout << "Attaque apres item : " << attaque << endl;

        return true;
    }
    return false;
}
void Joueur::ajouterVictoire()
{
    nbVictoires++;
}

void Joueur::incrementerTue()
{
    nbMonstreTues++;
}

void Joueur::incrementerEpargner()
{
    nbMonstresEpargnes++;
}

bool Joueur::aGagne() const
{
    if (nbVictoires >= 10)
    {
        return true;
    }
    return false;
}
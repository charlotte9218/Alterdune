#include "chargement.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

vector<Items> chargerItems(string filename)
{
    vector<Items> items;
    ifstream file("data/" + filename);

    if (!file)
    {
        cout << "Erreur ouverture fichier items : " << filename << endl;
        return items;
    }

    string ligne;

    while (getline(file, ligne))
    {
        if (ligne == "")
        {
            continue;
        }

        stringstream ss(ligne);

        string nom;
        string type;
        string valeur;
        string quantite;

        getline(ss, nom, ';');
        getline(ss, type, ';');
        getline(ss, valeur, ';');
        getline(ss, quantite, ';');

        if (nom == "nom")
        {
            continue;
        }

        itemType t = HEAL;

        Items i(nom, t, stoi(quantite), stoi(valeur));
        items.push_back(i);
    }

    file.close();
    return items;
}

vector<Monstres> chargerMonstres(string filename)
{
    vector<Monstres> monstres;
    ifstream file("data/" + filename);

    if (!file)
    {
        cout << "Erreur ouverture fichier monstres : " << filename << endl;
        return monstres;
    }

    string ligne;

    while (getline(file, ligne))
    {
        if (ligne == "")
        {
            continue;
        }

        stringstream ss(ligne);

        string categorie;
        string nom;
        string hp;
        string atk;
        string def;
        string mercyGoal;
        string act1;
        string act2;
        string act3;
        string act4;

        getline(ss, categorie, ';');
        getline(ss, nom, ';');
        getline(ss, hp, ';');
        getline(ss, atk, ';');
        getline(ss, def, ';');
        getline(ss, mercyGoal, ';');
        getline(ss, act1, ';');
        getline(ss, act2, ';');
        getline(ss, act3, ';');
        getline(ss, act4, ';');

        if (categorie == "categorie")
        {
            continue;
        }

        Monstres m(nom, stoi(hp), stoi(atk), stoi(def), stoi(mercyGoal));
        monstres.push_back(m);
    }

    file.close();
    return monstres;
}
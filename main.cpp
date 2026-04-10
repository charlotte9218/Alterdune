#include <iostream>
#include <vector>
#include "joueur.h"
#include "monstres.h"
#include "items.h"
#include "chargement.h"

using namespace std;

int main()
{
    Joueur j("Link", 100, 20, 5);
    Monstres m("Bokoblin", 30, 10, 2, 100);

    cout << "=== JOUEUR ===" << endl;
    j.Statistiques();

    cout << endl;

    cout << "=== MONSTRE ===" << endl;
    m.Statistiques();

    cout << endl;

    m.Attaque(j);

    cout << endl;
    cout << "=== JOUEUR APRES ATTAQUE ===" << endl;
    j.Statistiques();

    vector<Items> listeItems = chargerItems("items.csv");
    vector<Monstres> listeMonstres = chargerMonstres("monsters.csv");

    cout << endl;
    cout << "=== ITEMS CHARGES ===" << endl;

    for (int i = 0; i < listeItems.size(); i++)
    {
        cout << listeItems[i].getNom() << endl;
    }

    cout << endl;
    cout << "=== MONSTRES CHARGES ===" << endl;

    for (int i = 0; i < listeMonstres.size(); i++)
    {
        listeMonstres[i].Statistiques();
        cout << endl;
    }

    return 0;
}
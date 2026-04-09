#include <iostream>
#include "bestiaire.h"

using namespace std;

Bestiaires::Bestiaires()
{
    NbVaincus = 0;
}

void Bestiaires::ajouterMonstre(Monstres m)
{
    MonstresVaincus.push_back(m);
    NbVaincus++;
}

void Bestiaires::AffichageB()
{
    cout << "===== BESTIAIRE =====" << endl;

    cout << "Nombre de monstres vaincus : "
         << NbVaincus << endl << endl;

    for(int i = 0; i < MonstresVaincus.size(); i++)
    {
        MonstresVaincus[i].Statistiques();
        cout << endl;
    }
}
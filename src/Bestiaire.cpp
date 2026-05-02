#include "../include/Bestiaire.h"
#include <iostream>
using namespace std;

Bestiaire::Bestiaire() {}

Bestiaire::~Bestiaire()
{
    for (int i = 0; i < monstresVaincus.size(); i++)
    {
        delete monstresVaincus[i];
    }
}

void Bestiaire::AjouterMonstre(const Monstre* m)
{
    if (!DejaEnregistre(m->GetNom()))
    {
        monstresVaincus.push_back(m->Clone());
        cout << "[Bestiaire] " << m->GetNom() << " ajouté au bestiaire !" << endl;
    }
}

bool Bestiaire::DejaEnregistre(const string& nom) const
{
    for (int i = 0; i < monstresVaincus.size(); i++)
    {
        if (monstresVaincus[i]->GetNom() == nom)
            return true;
    }
    return false;
}

void Bestiaire::Afficher() const
{
    cout << "\n===== BESTIAIRE =====" << endl;
    cout << "Monstres découverts : " << monstresVaincus.size() << endl << endl;

    if (monstresVaincus.empty())
    {
        cout << "Aucun monstre vaincu pour l'instant." << endl;
        return;
    }

    for (int i = 0; i < monstresVaincus.size(); i++)
    {
        cout << "--- #" << (i + 1) << " ---" << endl;
        monstresVaincus[i]->afficherStatistiques();
        cout << endl;
    }
}
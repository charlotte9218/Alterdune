#include <iostream>
#include "Bestiaire.h"

using namespace std;

Bestiaires::Bestiaires()
{
    NbVaincus = 0;
}

void Bestiaires::ajouterMonstre(Monstre *m)
{
    if (m == nullptr)
    {
        return;
    }

    if (!dejaVaincu(m->getNom()))
    {
        MonstresVaincus.push_back(m);
        NbVaincus++;
        cout << "[Bestiaire] Nouveau monstre enregistre : " << m->getNom() << endl;
    }
    else
    {
        cout << "[Bestiaire] " << m->getNom() << " est deja dans le bestiaire." << endl;
    }
}

bool Bestiaires::dejaVaincu(const string &nom) const
{
    for (int i = 0; i < MonstresVaincus.size(); i++)
    {
        if (MonstresVaincus[i]->getNom() == nom)
        {
            return true;
        }
    }

    return false;
}

Monstre *Bestiaires::chercherMonstre(const string &nom)
{
    for (int i = 0; i < MonstresVaincus.size(); i++)
    {
        if (MonstresVaincus[i]->getNom() == nom)
        {
            return MonstresVaincus[i];
        }
    }

    return nullptr;
}

int Bestiaires::getNbVaincus() const
{
    return NbVaincus;
}

const vector<Monstre *> &Bestiaires::getMonstres() const
{
    return MonstresVaincus;
}

void Bestiaires::AffichageB() const
{
    cout << "===== BESTIAIRE =====" << endl;
    cout << "Monstres vaincus : " << NbVaincus << endl
         << endl;

    if (NbVaincus == 0)
    {
        cout << "Aucun monstre vaincu pour l'instant." << endl;
        return;
    }

    for (int i = 0; i < MonstresVaincus.size(); i++)
    {
        cout << "--- Monstre #" << (i + 1) << " ---" << endl;
        MonstresVaincus[i]->afficherStatistiques();
        cout << "categorie: " << MonstresVaincus[i]->GetCategorie() << endl;
        cout << "Resultat : " << MonstresVaincus[i]->getResultat() << endl;
        cout << endl;
    }
}

void Bestiaires::AffichageResume() const
{
    cout << "===== BESTIAIRE resume =====" << endl;
    cout << "Monstres vaincus : " << NbVaincus << endl;

    for (int i = 0; i < MonstresVaincus.size(); i++)
    {
        cout << "  - " << MonstresVaincus[i]->getNom() << endl;
    }
}
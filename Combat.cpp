#include "Combat.h"
#include <iostream>
#include <cstdlib>
#include "Entite.h"

Combat::Combat(Monstres *m, Joueur *j)
{
    monstre = m;
    joueur = j;
}

bool Combat::executeCombat()
{
    while (joueur->estVivant() && monstre->estVivant())
    {

        afficherMenu();

        int choix;
        cin >> choix;

        switch (choix)
        {
        case 1:
            handleFight();
            break;
        case 2:
            handleAct(); // Pas encore défini
            break;
        case 3:
            handleItem(); // pas encore défini
            break;
        case 4:
            if (handleMercy())
                return true; // pas encore défini
            break;
        default:
            cout << "Choix invalide\n";
        }

        // Tour du monstre
        if (monstre->estVivant())
        {
            appliquerDegat(monstre->Degat(), monstre->getHPRef());
        }
    }

    if (!joueur->estVivant())
    {
        cout << "Vous avez perdu...\n";
        return false;
    }

    cout << "Victoire !\n";
    return true;
}

void Combat::afficherMenu()
{
    cout << "FIGHT ACT ITEM MERCY";
}

void appliquerDegat(int degat, int &currentHP)
{
    if (degat == 0)
    {
        std::cout << "Coup rate !\n";
        return;
    }

    currentHP = currentHP - degat;

    if (currentHP < 0)
    {
        currentHP = 0;
    }

    std::cout << "-" << degat << " HP\n";
}

void Combat::handleFight()
{
    int d = monstre->Degat();
    appliquerDegat(d, monstre->getHPRef());
    if (monstre->getHP() == 0)
    {
        cout << "Monstre tué";
    }
}

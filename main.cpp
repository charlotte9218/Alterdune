#include <iostream>
#include "joueur.h"
#include "monstres.h"

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

    return 0;
}
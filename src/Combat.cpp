#include "../include/Combat.h"
#include <iostream>
using namespace std;

Combat::Combat(Joueur *joueur, Monstre *monstre, map<string, Act> *catalogueAct)
{
    this->joueur = joueur;
    this->monstre = monstre;
    this->catalogueAct = catalogueAct;
    this->combatGagne = false;
}
void Combat::AfficherMenu() const
{
    cout << "\n===== COMBAT =====" << endl;
    cout << "1. FIGHT" << endl;
    cout << "2. ACT" << endl;
    cout << "3. ITEM" << endl;
    cout << "4. MERCY" << endl;
    cout << "Votre choix : (en chiffre)";
}

void Combat::ActionFight()
{
    int degat = rand() % (monstre->GetHPMax() + 1);
    cout << "Vous attaquer le monstre qui subit: " << degat << " HP." << endl;
    monstre->subirDegats(degat);
    if (monstre->estEnVie() == false)
    {
        cout << " Felicitations vous avez tue le monstre !!!" << endl;
        joueur->ajouterVictoire();
        joueur->incrementerTue();
        combatGagne = true;
    }
}
void Combat::TourMonstre()
{
    int degat = rand() % (joueur->GetHPMax() + 1);
    cout << "Le monstre attaque  le joueur qui subit: " << degat << " HP." << endl;
    joueur->subirDegats(degat);
    if (joueur->estEnVie() == false)
    {
        cout << "Le monstre a gagne la partie !!!" << endl;
        combatGagne = true;
    }
}

void Combat::ActionAct()
{
    // Afficher les actions
    vector<string> actions = monstre->GetActions();
    int index;
    for (int i = 0; i < monstre->NbActionsAct(); i++)
    {
        cout << i << " : " << actions[i] << endl;
    }
    // Choisir une actions
    cout << "Choisissez uhne action" << endl;
    cin >> index;
    if (index < 0 || index >= monstre->NbActionsAct())
    {
        cout << "Action invalide." << endl;
        return;
    }

    string id = actions[index];
    Act act = (*catalogueAct)[id];
    act.Afficher();
    monstre->modifierMercy(act.GetImpactMercy());
    cout << "Mercy : " << monstre->GetMercy() << "/" << monstre->GetMercyObjectif() << endl;
}

void Combat::ActionItem()
{
    cout << "Inventaire: " << endl;
    joueur->AfficherInventaire();

    int item;
    cout << "Choisissez un item (index) : ";
    cin >> item;

    if (joueur->UtiliserItem(item) == true)
    {
        cout << "Item utilise avec succes !" << endl;
    }
    else
    {
        cout << "Item invalide ou non disponible." << endl;
    }
}

void Combat::ActionMercy()
{
    if (monstre->peutEtreEpargner() == true)
    {
        cout << "Vous epargnez le monstre !" << endl;
        joueur->ajouterVictoire();
        joueur->incrementerEpargner();
        combatGagne = true;
    }
    else
    {
        cout << "Monstre ne peut pas etre epargne";
    }
}

void Combat::Lancer()
{
    int choix;
    while (joueur->estEnVie() == true && monstre->estEnVie() == true && combatGagne == false)
    {
        cout << "Voici les stats du monstre" << endl;
        monstre->afficherStatistiques();
        cout << endl;
        AfficherMenu();
        cin >> choix;
        switch (choix)
        {
        case 1:
            ActionFight();
            break;
        case 2:
            ActionAct();
            break;
        case 3:
            ActionItem();
            break;
        case 4:
            ActionMercy();
            break;
        default:
            cout << "Choix invalide" << endl;
        }

        if (monstre->estEnVie() && joueur->estEnVie() && !combatGagne)
        {
            joueur->afficherStatistiques();
            TourMonstre();
        }
    }
}

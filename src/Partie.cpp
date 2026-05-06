#include "../include/Partie.h"
#include <iostream>
#include <fstream> //charger les doc
#include <sstream>

#include <cstdlib>
#include <ctime>
using namespace std;

Partie::Partie()
{
    joueur = nullptr;
}

Partie::~Partie()
{
    delete joueur;

    for (int i = 0; i < listeMonstres.size(); i++)
    {
        delete listeMonstres[i];
    }
}

void Partie::InitialiserCatalogueAct()
{
    catalogueAct["COMPLIMENTER"] = Act("COMPLIMENTER", "Tu fais un compliment au monstre.", 15);
    catalogueAct["MOQUER"] = Act("MOQUER", "Tu te moques du monstre.", -10);
    catalogueAct["INSULTER"] = Act("INSULTER", "Tu insultes le monstre.", -15);
    catalogueAct["EPARGNER"] = Act("EPARGNER", "Tu montres de la compassion.", 20);
    catalogueAct["COURAGE"] = Act("COURAGE", "Tu encourages le monstre.", 10);
    catalogueAct["NOURRIR"] = Act("NOURRIR", "Tu offres de la nourriture.", 15);
    catalogueAct["NARGUER"] = Act("NARGUER", "Tu nargues le monstre.", -5);
    catalogueAct["PARIER"] = Act("PARIER", "Tu proposes un pari risque.", 5);
}

vector<Item> Partie::ChargerItems()
{
    vector<Item> items; // creation tab dynamique

    // ouverture du fichier
    ifstream fichier("data/Items.csv");

    // verification que le fichier est bien ouvert
    if (!fichier.is_open())
    {
        cout << "Erreur : impossible d'ouvrir data/Items.csv" << endl;
        return items;
    }

    // lecture ligne par ligne du fichier
    string ligne;

    while (getline(fichier, ligne))
    {
        try
        {
            stringstream ss(ligne);

            // on stocke chaque champ séparément
            string nom, type;
            string valeurStr, quantiteStr;

            // découpage du csv et récupèration des informations
            getline(ss, nom, ';');
            getline(ss, type, ';');

            // récupération des nombres sous forme de string
            getline(ss, valeurStr, ';');
            getline(ss, quantiteStr, ';');

            // changement de string en int
            int valeur = stoi(valeurStr);
            int quantite = stoi(quantiteStr);

            // creation d'un item
            Item item(nom, type, valeur, quantite);

            // ajoute l'item dans la liste
            items.push_back(item);
        }

        // gestion des erreurs de conversion
        catch (const invalid_argument &e)
        {
            cout << "Erreur de conversion dans la ligne : "
                 << ligne << endl;

            cout << e.what() << endl;
        }
    }

    return items;
}

void Partie::ChargerMonstres()
{
    // ouverture du fichier
    ifstream fichier("data/Monsters.csv");

    // verification que le fichier est bien ouvert
    if (!fichier.is_open())
    {
        cout << "Erreur : impossible d'ouvrir data/Monsters.csv" << endl;
        return;
    }

    // lecture ligne par ligne du fichier
    string ligne;

    while (getline(fichier, ligne))
    {
        try
        {
            stringstream ss(ligne);

            // on stocke chaque champ séparément
            string categorie, nom;
            string hpStr, atkStr, defStr, mercyStr;
            string act1, act2, act3, act4;

            // découpage du csv et récupèration des informations
            getline(ss, categorie, ';');
            getline(ss, nom, ';');
            getline(ss, hpStr, ';');
            getline(ss, atkStr, ';');
            getline(ss, defStr, ';');
            getline(ss, mercyStr, ';');
            getline(ss, act1, ';');
            getline(ss, act2, ';');
            getline(ss, act3, ';');
            getline(ss, act4, ';');

            // changement de string en int
            int hp = stoi(hpStr);
            int atk = stoi(atkStr);
            int def = stoi(defStr);
            int mercyObjectif = stoi(mercyStr);

            // creation du tableau dynamique d'actions
            vector<string> actions;

            // ajout des actions disponibles
            if (act1 != "-")
            {
                actions.push_back(act1);
            }

            if (act2 != "-")
            {
                actions.push_back(act2);
            }

            if (act3 != "-")
            {
                actions.push_back(act3);
            }

            if (act4 != "-")
            {
                actions.push_back(act4);
            }

            // creation du bon type de monstre
            if (categorie == "NORMAL")
            {
                listeMonstres.push_back(
                    new Normal(nom, hp, atk, def, mercyObjectif, actions));
            }

            else if (categorie == "MINIBOSS")
            {
                listeMonstres.push_back(
                    new MiniBoss(nom, hp, atk, def, mercyObjectif, actions));
            }

            else if (categorie == "BOSS")
            {
                listeMonstres.push_back(
                    new Boss(nom, hp, atk, def, mercyObjectif, actions));
            }
        }

        // gestion des erreurs de conversion
        catch (const invalid_argument &e)
        {
            cout << "Erreur de conversion dans la ligne : "
                 << ligne << endl;

            cout << e.what() << endl;
        }
    }
}

void Partie::AfficherResume()
{
    cout << "Resume : " << endl;
    joueur->afficherStatistiques();

    cout << " Inventaire " << "\n"
         << endl;
    joueur->AfficherInventaire();
}

void Partie::AfficherMenu()
{
    cout << "\n===== MENU PRINCIPAL =====" << endl;
    cout << "1. Bestiaire" << endl;
    cout << "2. Demarrer un combat" << endl;
    cout << "3. Statistiques du personnage" << endl;
    cout << "4. Items" << endl;
    cout << "5. Quitter" << endl;
    cout << "Votre choix : ";
}

void Partie::InitialiserPartie()
{
    InitialiserCatalogueAct();
    vector<Item> items = ChargerItems();
    string nom;
    cout << "Entrez le nom du joueur : ";
    cin >> nom;

    joueur = new Joueur(nom, 1000, 350, 5, items); // Joueur(string nom, int HP_Max, int attaque, int defense, vector<Item> inventaire)
    ChargerMonstres();

    AfficherResume();
}

void Partie::LancerCombat()
{
    if (listeMonstres.empty())
    {
        cout << "Aucun monstre disponible." << endl;
        return;
    }

    int index = rand() % listeMonstres.size();

    Monstre *monstreCombat = listeMonstres[index]->Clone();

    Combat combat(joueur, monstreCombat, &catalogueAct);
    combat.Lancer();

    if (!monstreCombat->estEnVie() || monstreCombat->peutEtreEpargner())
    {
        bestiaire.ajouterMonstre(monstreCombat);
    }
}

void Partie::LancerJeu()
{
    int choix;

    while (!FinPartie())
    {
        AfficherMenu();
        cin >> choix;

        switch (choix)
        {
        case 1:
            bestiaire.AffichageB();
            break;
        case 2:
            LancerCombat();
            break;
        case 3:
            joueur->afficherStatistiques();
            break;
        case 4:
            joueur->AfficherInventaire();
            char c;
            cout << "Voulez vous utiliser l'item(O/N)" << endl;
            cin >> c;
            if (c != 'O' || c != 'N')
            {
                cout << "Votre réponse est différente de O ou N" << endl;
                cout << "Voulez vous utiliser l'item(O/N)" << endl;
                cin >> c;
            }
            if (c == 'O')
            {
                int num;
                cout << "Rentrer le numero de l'Item" << endl;
                cin >> num;
                joueur->UtiliserItem(num);
            }
            break;
        case 5:

            AfficherFin();
            return;

        default:

            cout << "Choix invalide" << endl;
        }
    }
    AfficherFin();
}

bool Partie::FinPartie() const
{
    if (joueur->aGagne() == true || joueur->estEnVie() == false)
    {
        return true;
    }
    return false;
}

void Partie::AfficherFin()
{
    cout << "\n FIN DE LA PARTIE: " << endl;
    if (joueur->estEnVie() == true)
    {
        if (joueur->GetNbMonstresEpargnes() == 0 && joueur->GetNbMonstreTues() == 10)
        {
            cout << "Fin Genocidaire : vous avez tue tous les monstres vaincus." << endl;
        }
        else if (joueur->GetNbMonstreTues() == 0 && joueur->GetNbMonstresEpargnes() == 0)
        {
            cout << "Fin Pacifiste : vous avez epargne tous les monstres vaincus." << endl;
        }
        else if (joueur->GetNbMonstreTues() + joueur->GetNbMonstresEpargnes() == 10)
        {
            cout << "Fin Neutre : vous avez tue et epargne des monstres." << endl;
        }
        else
        {
            cout << "Vous avez quitter le jeu" << endl;
        }
    }
    else
    {
        cout << "Le monstre a gagne la partie!!!" << endl;
    }

    cout << "Statistiques du Joueur:" << endl;
    joueur->afficherStatistiques();
}
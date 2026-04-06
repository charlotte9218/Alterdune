#ifndef ITEMS_H
#define ITEMS_H

#include <string>

using namespace std;

enum itemType
{
    HEAL
};

class Items
{
private:
    string nom;
    itemType Type;
    int quantiteDispo;
    int Valeur;

public:
    Items();
    Items(string nom, itemType Type, int quantiteDispo, int Valeur);
};

#endif
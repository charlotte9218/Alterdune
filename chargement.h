#ifndef CHARGEMENT_H
#define CHARGEMENT_H

#include <vector>
#include <string>
#include "items.h"
#include "monstres.h"

using namespace std;

vector<Items> chargerItems(string filename);
vector<Monstres> chargerMonstres(string filename);

#endif
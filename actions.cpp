#include "actions.h"
#include "monstres.h"
#include <map>

map<string, Actions> catalogue = {
    {"complimenter", {"complimenter", "tu complimentes le monstre", +15}},
    {"moquer", {"moquer", "tu te moques du monstre", -5}},
    {"raisonner", {"raisonner", "tu raisonnes avec le monstre", +7}},
    {"epargner", {"epargner", "le monstre t'épargne", +13}},
    {"chanter", {"chanter", "tu chantes faux au monstre", -20}},
    {"negocier", {"negocier", "tu negocie avec le monstre", +4}},
    {"flatter", {"flatter", "La flatterie ne te menera null part", +1}},
    {"esquiver", {"esquiver", "waw quelle esquive", +20}}};
Actions::Actions()
{
    IdAction = "";
    texteAffiche = "";
    MercyImpact = 0;
}

Actions::Actions(string IdAction, string texteAffiche, int MercyImpact)
{
    this->IdAction = IdAction;
    this->texteAffiche = texteAffiche;
    this->MercyImpact = MercyImpact;
}

string Actions::getIdAction()
{
    return IdAction;
}

string Actions::getTexteAffiche()
{
    return texteAffiche;
}

int Actions::getMercyImpact()
{
    return MercyImpact;
}

void Actions::setIdAction(string IdAction)
{
    this->IdAction = IdAction;
}

void Actions::setTexteAffiche(string texteAffiche)
{
    this->texteAffiche = texteAffiche;
}

void Actions::setMercyImpact(int MercyImpact)
{
    this->MercyImpact = MercyImpact;
}

void Actions::execute(Monstres &m)
{
    cout << texteAffiche << endl;
    m.modifierMercy(this->MercyImpact);
}
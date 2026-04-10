#include "actions.h"
#include "monstres.h"

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
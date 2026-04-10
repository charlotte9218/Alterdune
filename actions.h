#ifndef ACTIONS_H
#define ACTIONS_H

#include <iostream>
#include <string>

using namespace std;

class Monstres;

class Actions
{
private:
    string IdAction;
    string texteAffiche;
    int MercyImpact;

public:
    Actions();
    Actions(string IdAction, string texteAffiche, int MercyImpact);

    string getIdAction();
    string getTexteAffiche();
    int getMercyImpact();

    void setIdAction(string IdAction);
    void setTexteAffiche(string texteAffiche);
    void setMercyImpact(int MercyImpact);

    void execute(Monstres &m);
};

#endif
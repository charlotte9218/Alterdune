#ifndef ACT_H
#define ACT_H
#include <string>
using namespace std;

class Act
{
private:
    string id_Act;
    string texte;
    int impactMercy;

public:
    Act();
    Act(string id_Act, string texte, int impactMercy);
    string GetId() const;
    string GetTexte() const;
    int GetImpactMercy() const;

    void Afficher() const;
};
#endif

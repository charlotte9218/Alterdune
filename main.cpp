

#include "include/Partie.h"
#include <ctime>
#include <cstdlib>

int main()
{
    srand(time(0));

    Partie partie;
    partie.InitialiserPartie();
    partie.LancerJeu();

    return 0;
}

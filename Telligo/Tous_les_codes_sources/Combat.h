#ifndef COMBAT
#define COMBAT
#include "Personnage.h"

class Combat{
    public:
    Combat(Personnage &personne1, Personnage &personne2);
    void Combatamort();

    private:
    Personnage& perso1;
    Personnage& perso2;
};
#endif // COMBAT

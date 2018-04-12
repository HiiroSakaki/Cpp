#ifndef UNDEAD
#define UNDEAD
#include "Personnage.h"

class Undead : public Personnage{
    public:
    Undead();
    Undead(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void attaquevampirique(Personnage &perso2);
    void malediction(Personnage &perso2);
    void froidglacial(Personnage &perso2);
    virtual void attaque(Personnage &perso2);
    virtual ~Undead();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // UNDEAD

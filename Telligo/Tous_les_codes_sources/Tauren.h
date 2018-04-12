#ifndef TAUREN
#define TAUREN
#include "Personnage.h"

class Tauren : public Personnage{
    public:
    Tauren();
    Tauren(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void ruade(Personnage &perso2);
    void concentration();
    void chocmartial(Personnage &perso2);
    virtual void attaque(Personnage &perso2);
    virtual ~Tauren();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // TAUREN

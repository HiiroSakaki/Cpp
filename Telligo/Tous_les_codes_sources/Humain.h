#ifndef HUMAIN
#define HUMAIN
#include "Personnage.h"

class Humain : public Personnage{
    public:
    Humain();
    Humain(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void eclairdivin(Personnage &perso2);
    void foidupaladin();
    void soinconfession();
    virtual void attaque(Personnage &perso2);
    virtual ~Humain();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // HUMAIN

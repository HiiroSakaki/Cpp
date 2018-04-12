#ifndef NIGHTELF
#define NIGHTELF
#include "Personnage.h"

class NightElf : public Personnage{
    public:
    NightElf();
    NightElf(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void draindemana(Personnage &perso2);
    void sacrificemana(Personnage &perso2);
    void sagessedelanature();
    virtual void attaque(Personnage &perso2);
    virtual ~NightElf();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // NIGHTELF

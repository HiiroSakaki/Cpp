#ifndef BLOODELF
#define BLOODELF
#include "Personnage.h"

class BloodElf : public Personnage{
    public:
    BloodElf();
    BloodElf(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void draindesang(Personnage &perso2);
    void sacrificedesang(Personnage &perso2);
    void puissancedelanature(Personnage &perso2);
    virtual void attaque(Personnage &perso2);
    virtual ~BloodElf();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // BLOODELF

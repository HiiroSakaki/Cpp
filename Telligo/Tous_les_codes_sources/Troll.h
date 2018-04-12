#ifndef TROLL
#define TROLL
#include "Personnage.h"

class Troll : public Personnage{
    public:
    Troll();
    Troll(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void berserker();
    void regeneration();
    void armedejet();
    virtual void attaque(Personnage &perso2);
    virtual ~Troll();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // TROLL

#ifndef NAIN
#define NAIN
#include "Personnage.h"

class Nain : public Personnage{
    public:
    Nain();
    Nain(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void eboulement(Personnage &perso2);
    void armuredemithril();
    void naindelamontagne();
    virtual void attaque(Personnage &perso2);
    virtual ~Nain();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // NAIN

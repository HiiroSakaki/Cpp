#ifndef GOBELIN
#define GOBELIN
#include "Personnage.h"

class Gobelin : public Personnage{
    public:
    Gobelin();
    Gobelin(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void explosion(Personnage &perso2);
    void zeppelin();
    void apprentichimiste();
    virtual void attaque(Personnage &perso2);
    virtual ~Gobelin();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // GOBELIN

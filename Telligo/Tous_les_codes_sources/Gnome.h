#ifndef GNOME
#define GNOME
#include "Personnage.h"

class Gnome : public Personnage{
    public:
    Gnome();
    Gnome(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void confusion(Personnage &perso2);
    void forteresse();
    void loupe();
    virtual void attaque(Personnage &perso2);
    virtual ~Gnome();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // GNOME

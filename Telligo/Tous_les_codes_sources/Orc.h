#ifndef ORC
#define ORC
#include "Personnage.h"

class Orc : public Personnage{
    public:
    Orc();
    Orc(int vie, int mana, int atta, int def, int agil, int prec, string nom);

    void affiche();
    int coupspecial(Personnage &perso2);
    void piege(Personnage &perso2);
    void fureursanguinaire();
    void tourbillondelame(Personnage &perso2);
    virtual void attaque(Personnage &perso2);
    virtual ~Orc();

//    private:
//    int nbvie;
//    int nbmana;
//    int nbatta;
//    int nbdef;
//    int nbagil;
//    int nbprec;
//    string name;
};

#endif // ORC

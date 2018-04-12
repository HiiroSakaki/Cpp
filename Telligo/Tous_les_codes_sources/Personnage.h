#ifndef PERSONNAGE
#define PERSONNAGE
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

class Personnage{
    public:
    Personnage();//constructeur, cree un personnage
    Personnage(int vie, int mana, int atta, int def, int agil, int prec, string nom);//constructeur, cree un personnage
    int getvie();//nous informe de la vie d'un personnage, puisqu'on ne peut pas acceder directement a nbvie qui est un attribute private
    void setvie(int vie);// nous permet d'attribuer a notre personnage le nombre de point de vie: "vie".
    int getmana();
    void setmana(int mana);
    int getatta();
    void setatta(int atta);
    int getdef();
    void setdef(int def);
    int getagil();
    void setagil(int agil);
    int getprec();
    void setprec(int prec);
    string getnom();
    void setnom(string nom);
    virtual void affiche();
    int coupspecial(Personnage &perso2);
    void fight(Personnage &perso2);
    virtual void attaque(Personnage &perso2);
    virtual ~Personnage(); //le destructeur doit etre virtuel!

    protected:
    int nbvie;
    int nbmana;
    int nbatta;
    int nbdef;
    int nbagil;
    int nbprec;
    string name;

};
#endif // PERSONNAGE

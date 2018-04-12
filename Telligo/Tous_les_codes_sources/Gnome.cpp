#include "Gnome.h"
using namespace std;

Gnome::Gnome():Personnage(){}

Gnome::Gnome(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Gnome::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Gnome"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Gnome::confusion(Personnage &perso2){    //la confusion pousse l'adversaire a s'attaquer lui meme!!
    cout<< name + " a reussi a embrouiller "+ perso2.getnom()+" !!! "<<endl;
    nbmana=nbmana-10;
    perso2.fight(perso2);

        }

void Gnome::forteresse(){    //le gnome se terre dans sa forteresse il va etre difficile de l'attaquer!!
    cout<<  name +" se terre dans sa forteresse il va etre difficile de l'attaquer!!"<<endl;
    nbmana=nbmana-10;
    nbdef=nbdef+10;
    }

    void Gnome::loupe(){    //la loupe du gnome lui permet d'etre tres precis!!.
    cout<< "la loupe de "+ name +" lui permet d'etre tres precis!!. "<<endl;
    nbmana=nbmana-10;
    nbprec=nbprec+10;
    }

int Gnome::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour confusion(10), 2 pour forteresse(10), 3 pour loupe(10)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour confusion(10), 2 pour forteresse(10), 3 pour loupe(10)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<10){return 1;}
         else{
    confusion(perso2);
          return 0;}
    }
    case 2:
   {
        if (nbmana<10){return 1;}
         else{
            forteresse();
            return 0;}


    }
    case 3:
   {
               if (nbmana<10){return 1;}
         else{

                    loupe();
                    return 0;}
    }
}
}


void Gnome::attaque(Personnage &perso2)
{
    cout<<"\n"<<name +", Que voulez vous faire??? 1 pour attaquer, 2 pour coup special"<<endl;
    int choix;
    cin >> choix;
    while ((2-choix)*(1-choix)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"\n"<<name +", Que voulez vous faire??? 1 pour attaquer, 2 pour coup special"<<endl;
    cin >> choix;
        }
switch (choix)
{
     case 1: {
    fight(perso2);
          break;
    }
    case 2:
   {
        if (coupspecial(perso2)==1){
            cout<<"vous n'avez pas assez de mana"<<endl;
            attaque(perso2);}
            else {}

    }

}
}
Gnome::~Gnome(){}


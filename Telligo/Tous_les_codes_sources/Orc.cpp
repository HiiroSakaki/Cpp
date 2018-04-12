#include "Orc.h"
using namespace std;

Orc::Orc():Personnage(){}

Orc::Orc(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Orc::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Orc"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Orc::piege(Personnage &perso2){    //Le piege reduit de 50 l'agilite de l'adversaire et de 10 sa defense mais coute beaucoup de temps et donc de mana (50)
    cout<< name + " a pris au piege "+ perso2.getnom()+" !!! "<<endl;
    nbmana=nbmana-50;
    int agilperso2=perso2.getagil();
    if (50<agilperso2){perso2.setagil(agilperso2-50);}else{perso2.setagil(0);}
    int defperso2=perso2.getdef();
    if (10<defperso2){perso2.setdef(defperso2-10);}else{perso2.setdef(0);}
        }

void Orc::fureursanguinaire(){    //la fureur sanguinaire fait perdre de la vie, de la precision et de la defense a l'orc mais augmente considerablement son attaque
    cout<< name +" est assoife de sang!! "<<endl;
    int rage=rand()%20;
    nbmana=nbmana-10;
    nbatta=nbatta+3*rage;
    nbprec=nbprec-rage;
    nbdef=nbdef-rage;
    nbvie=nbvie-rage;
    }

    void Orc::tourbillondelame(Personnage &perso2){    //permet d'attaquer 3 fois mais coute 20 de mana
    nbmana=nbmana-20;
    cout<< "Oh!! "+ name +" utilise son troubillon de lames!!! "<<endl;
    fight(perso2);
    fight(perso2);
    fight(perso2);
          }


int Orc::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour piege(50), 2 pour fureur sanguinaire(10), 3 pour tourbillon de lames(20)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour piege(50), 2 pour fureur sanguinaire(10), 3 pour tourbillon de lames(20)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<50){return 1;}
         else{
    piege(perso2);
          return 0;}
    }
    case 2:
   {
        if (nbmana<10){return 1;}
         else{
            fureursanguinaire();
            return 0;}


    }
    case 3:
   {
        if (nbmana<20){return 1;}
         else{
            tourbillondelame(perso2);
            return 0;}
    }
}
}


void Orc::attaque(Personnage &perso2)
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
Orc::~Orc(){}


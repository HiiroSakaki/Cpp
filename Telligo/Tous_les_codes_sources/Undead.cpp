#include "Undead.h"
using namespace std;

Undead::Undead():Personnage(){}

Undead::Undead(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Undead::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Undead"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Undead::attaquevampirique(Personnage &perso2){    //le mort vivant absorbe une partie des points de vie qu'il prend a l'adversaire!!
    cout<< name + " lance une attaque vampirique sur "+ perso2.getnom()+" !!! "<<endl;
    nbmana=nbmana-5;
    int vieperso2=perso2.getvie();
    fight(perso2);
    int degats=perso2.getvie()-vieperso2;
    if (degats==1){nbvie=nbvie+1;}
    else{
    nbvie=nbvie+rand()%degats;}
        }

void Undead::malediction(Personnage &perso2){    //le mort vivant maudit son adversaire
    cout<<  name +" a maudit "+perso2.getnom()<<endl;
    nbmana=nbmana-10;
    int attaperdu=rand()%10;
    int defperdu=rand()%10;
    int agilperdu=rand()%10;
    int precperdu=rand()%10;
    int attaperso2=perso2.getatta();
    if (attaperdu>attaperso2){perso2.setatta(0);}else{perso2.setatta(attaperso2-attaperdu);}
    int defperso2=perso2.getdef();
    if (defperdu>defperso2){perso2.setdef(0);}else{perso2.setdef(defperso2-defperdu);}
    int agilperso2=perso2.getagil();
    if (agilperdu>agilperso2){perso2.setagil(0);}else{perso2.setagil(agilperso2-agilperdu);}
    int precperso2=perso2.getprec();
    if (precperdu>precperso2){perso2.setprec(0);}else{perso2.setprec(precperso2-precperdu);}

        }

    void Undead::froidglacial(Personnage &perso2){    //le mort vivant envoie un flux glacial a son adversaire.
    nbmana=nbmana-15;
    int degat=rand()%20;
    cout<<  name +" envoie un flux glacial sur"+ perso2.getnom()<<endl;
    int agilperso2=perso2.getagil();
    if (5<agilperso2){perso2.setagil(agilperso2-5);}else{perso2.setagil(0);}
    int vieperso2=perso2.getvie();
    if (degat<vieperso2){perso2.setvie(vieperso2-degat);}else{perso2.setvie(0);}
    }

int Undead::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour attaque vampirique(5), 2 pour malediction(10), 3 pour froid glacial(15)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour attaque vampirique(5), 2 pour malediction(10), 3 pour froid glacial(15)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<5){return 1;}
         else{
    attaquevampirique(perso2);
          return 0;}
    }
    case 2:
   {
         if (nbmana<10){return 1;}
         else{
    malediction(perso2);
          return 0;}
    }
    case 3:
   {
         if (nbmana<15){return 1;}
         else{
    froidglacial(perso2);
          return 0;}
    }
}
}


void Undead::attaque(Personnage &perso2)
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
Undead::~Undead(){}


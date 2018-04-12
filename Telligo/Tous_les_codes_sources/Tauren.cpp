#include "Tauren.h"
using namespace std;

Tauren::Tauren():Personnage(){}

Tauren::Tauren(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Tauren::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Tauren"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Tauren::chocmartial(Personnage &perso2){    //le choc martial blesse legerement l'adversaire mais reduit sa defense et sa precision!!
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    cout<< name + " fait trembler la terre!!! "<<endl;
    nbmana=nbmana-20;
    int vieperso2=perso2.getvie();
    int defperso2=perso2.getdef();
    int precperso2=perso2.getprec();
    int degat=rand()%20;
    if (degat<vieperso2){perso2.setvie(vieperso2-degat);}else{perso2.setvie(0);}
    if (3<defperso2){perso2.setdef(defperso2-3);}else{perso2.setdef(0);}
    if (3<precperso2){perso2.setprec(precperso2-3);}else{perso2.setprec(0);}
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
        }

void Tauren::ruade(Personnage &perso2){    //une serie d'attaque de moins en moins precise et efficace!!
    cout<< name +" envoie une multitude de coup!!! "<<endl;
    nbmana=nbmana-20;
    for(int i=0;i<5;i++){
    fight(perso2);
    nbatta=nbatta-10;
    nbprec=nbprec-10;}
    nbatta=nbatta+50;
    nbprec=nbprec+50;

        }

    void Tauren::concentration(){    //le tauren se concentre et augmente ses caracteristiques de 2.
    nbmana=nbmana-10;
    cout<<  name +" se concentre et augmente ses caracteristiques! "<<endl;
    nbatta=nbatta+2;
    nbdef=nbdef+2;
    nbagil=nbagil+2;
    nbprec=nbprec+2;
    }

int Tauren::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour choc martial(20), 2 pour ruade(20), 3 pour concentration(10)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour choc martial, 2 pour ruade, 3 pour concentration"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<20){return 1;}
         else{
        chocmartial(perso2);
          return 0;}
    }
    case 2:
   {
        if (nbmana<20){return 1;}
         else{
        ruade(perso2);
            return 0;}


    }
    case 3:
   {
        if (nbmana<10){return 1;}
         else{
            concentration();
            return 0;}


    }
}
}


void Tauren::attaque(Personnage &perso2)
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
Tauren::~Tauren(){}


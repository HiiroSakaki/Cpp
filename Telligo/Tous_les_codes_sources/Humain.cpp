#include "Humain.h"
using namespace std;

Humain::Humain():Personnage(){}

Humain::Humain(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Humain::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Humain"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Humain::eclairdivin(Personnage &perso2){    //l'eclair divin fait de terribles dommages a l'adversaire, pas moyen de l'esquiver!!
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    cout<< name + " lance un eclair a "+ perso2.getnom()+" !!! "<<endl;
    nbmana=nbmana-20;
    int vieperso2=perso2.getvie();
    int degat=rand()%20;
    if (degat<vieperso2){perso2.setvie(vieperso2-degat);}else{perso2.setvie(0);}
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
        }

void Humain::foidupaladin(){    //la fois du paladin lui ajoute force et precision!!
    cout<< "La foi de "+ name +" lui confere force et precision!!! "<<endl;
    nbmana=nbmana-10;
    nbatta=nbatta+rand()%10;
    nbprec=nbprec+rand()%10;
    }

    void Humain::soinconfession(){    //la confession permet au croyant de regagner d'echanger mana et vie.
          int nbechange=rand()%40;
    cout<< "La confession de "+ name +" lui permet de gagner des points de vie!!! "<<endl;
          if (nbmana >nbechange) {
                nbmana=nbmana-nbechange;
                nbvie=nbvie+nbechange;}
          else{
                nbvie=nbvie+nbmana;
                nbmana=0;
          }
    }

int Humain::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour eclair divin(20), 2 pour foi du paladin(10), 3 pour soin confession"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour eclair divin(20), 2 pour foi du paladin(10), 3 pour soin confession"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<20){return 1;}
         else{
    eclairdivin(perso2);
          return 0;}
    }
    case 2:
   {
        if (nbmana<10){return 1;}
         else{
            foidupaladin();
            return 0;}


    }
    case 3:
   {
        soinconfession();
            return 0;
    }
}
}


void Humain::attaque(Personnage &perso2)
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
Humain::~Humain(){}


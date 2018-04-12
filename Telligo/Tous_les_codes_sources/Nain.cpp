#include "Nain.h"
using namespace std;

Nain::Nain():Personnage(){}

Nain::Nain(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Nain::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Nain"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Nain::eboulement(Personnage &perso2){    //le nain provoque un eboulement!!
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    cout<< name + " provoque un eboulement "<<endl;
    nbmana=nbmana-20;
    int vieperso2=perso2.getvie();
    int defperso2=perso2.getdef();
    int agilperso2=perso2.getagil();
    int degat=rand()%20;
    int baissedef=rand()%20;
    int baisseagil=rand()%20;
    if (degat<vieperso2){perso2.setvie(vieperso2-degat);}else{perso2.setvie(0);}
    if (baissedef<defperso2){perso2.setdef(defperso2-baissedef);}else{perso2.setdef(0);}
    if (baisseagil<agilperso2){perso2.setagil(agilperso2-baisseagil);}else{perso2.setagil(0);}
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
        }

void Nain::armuredemithril(){    //l'armure de mithril est reputee incassable
    cout<<  name +" enfile son armure en mithril!!! "<<endl;
    nbmana=nbmana-10;
    nbdef=nbdef+rand()%20;
    }

    void Nain::naindelamontagne(){    //le nain se transforme en nain de la montagne.
    nbmana=nbmana-100;
    cout<<  name +" se transforme en nain de la montagne!!! "<<endl;
    nbvie=nbvie+rand()%100;
    nbatta=nbatta+rand()%100;
    nbdef=nbdef+rand()%100;
    nbagil=nbagil+rand()%100;
    nbprec=nbprec+rand()%100;



    }

int Nain::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour eboulement(20) 2 pour armure de mithril(10), 3 pour nain de la montagne(100)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour eboulement(20) 2 pour armure de mithril(10), 3 pour nain de la montagne(100)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<20){return 1;}
         else{
    eboulement(perso2);
          return 0;}
    }
    case 2:
   {
        if (nbmana<10){return 1;}
         else{
            armuredemithril();
            return 0;}


    }
    case 3:
   {
        if (nbmana<100){return 1;}
         else{
            naindelamontagne();
            return 0;}


    }
}
}


void Nain::attaque(Personnage &perso2)
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
Nain::~Nain(){}


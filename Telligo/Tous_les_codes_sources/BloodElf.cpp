#include "BloodElf.h"
using namespace std;

BloodElf::BloodElf():Personnage(){}

BloodElf::BloodElf(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void BloodElf::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: BloodElf"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void BloodElf::draindesang(Personnage &perso2){    //l'elfe de sang peut aspirer les points de vie de son adversaire et les transformer en mana
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    cout<< name + " aspire le sang de "+ perso2.getnom()+" !!! "<<endl;
    nbmana=nbmana-10;
    int degat=rand()%10;
    int vieperso2=perso2.getvie();
    if (degat<vieperso2){perso2.setvie(vieperso2-degat); nbmana=nbmana+degat;}else{perso2.setvie(0); nbmana=nbmana+vieperso2;}
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
        }

void BloodElf::sacrificedesang(Personnage &perso2){    //l'elfe de sang sacrifie sa vie pour affaiblir son adversaire!
    cout<< name +" sacrifie sa vie pour affaiblir "+ perso2.getnom()<<endl;
    nbmana=nbmana-10;
    int sacrifice=rand()%10;
    int vraisacrifice;
    if (sacrifice<nbvie) {vraisacrifice=sacrifice;} else{if (sacrifice==nbvie){vraisacrifice=nbvie-1;}else{vraisacrifice=nbvie;}}
    int vieperso2=perso2.getvie();
    if (2*vraisacrifice<vieperso2){perso2.setvie(vieperso2-2*vraisacrifice); nbvie=nbvie-vraisacrifice; }else{perso2.setvie(0); nbvie=nbvie-vraisacrifice;}
    }

    void BloodElf::puissancedelanature(Personnage &perso2){    //l'elfe communie avec la nature, cela lui permet d'affaiblir les caracteristiques de son adversaire.
          nbmana=nbmana-10;
          int nbechange=rand()%5;
    cout<< name +" communie avec la nature, cela lui permet d'affaiblir les caracteristiques de "+ perso2.getnom()<<endl;
        int attaperso2=perso2.getatta();
        if (nbechange>attaperso2){perso2.setatta(0);}else{perso2.setatta(attaperso2-nbechange);}
        int defperso2=perso2.getdef();
        if (nbechange>defperso2){perso2.setdef(0);}else{perso2.setdef(defperso2-nbechange);}
        int agilperso2=perso2.getagil();
        if (nbechange>agilperso2){perso2.setagil(0);}else{perso2.setagil(agilperso2-nbechange);}
        int precperso2=perso2.getprec();
        if (nbechange>precperso2){perso2.setprec(0);}else{perso2.setprec(precperso2-nbechange);}
    }

int BloodElf::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour drain de sang(10), 2 pour sacrifice de sang, 3 pour puissance de la nature(10)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour drain de sang(10), 2 pour sacrifice de sang, 3 pour puissance de la nature(10)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<10){return 1;}
         else{
    draindesang(perso2);
          return 0;}
    }
    case 2:
   {

        sacrificedesang(perso2);
            return 0;


    }
    case 3:
   {
        if (nbmana<10){return 1;}
         else{
        puissancedelanature(perso2);
            return 0;}
    }
}
}


void BloodElf::attaque(Personnage &perso2)
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
BloodElf::~BloodElf(){}


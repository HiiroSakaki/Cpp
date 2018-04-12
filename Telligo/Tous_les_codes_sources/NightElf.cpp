#include "NightElf.h"
using namespace std;

NightElf::NightElf():Personnage(){}

NightElf::NightElf(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void NightElf::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: NightElf"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void NightElf::draindemana(Personnage &perso2){    //l'elfe de la nuit peut aspirer les points de mana de son adversaire et les transformer en point de vie
    cout<<"Point de vie de "+name +":   "<<nbvie<<endl;
    cout<< name + " aspire le mana de "+ perso2.getnom()+" !!! "<<endl;
    nbmana=nbmana-10;
    int degat=rand()%10;
    int manaperso2=perso2.getmana();
    if (degat<manaperso2){perso2.setmana(manaperso2-degat); nbvie=nbvie+degat;}else{perso2.setmana(0); nbvie=nbvie+manaperso2;}
    cout<<"Point de vie de "+name +":   "<<nbvie<<endl;
        }

void NightElf::sacrificemana(Personnage &perso2){    //l'elfe de la nuit sacrifie son mana pour detruire le mana de son adversaire!
    cout<< name +" sacrifie son mana pour detruire le mana de "+ perso2.getnom()<<endl;
    int sacrifice=rand()%10;
    int vraisacrifice;
    if (sacrifice<nbmana) {vraisacrifice=sacrifice;} else{vraisacrifice=nbmana;}
    int manaperso2=perso2.getmana();
    if (2*vraisacrifice<manaperso2){perso2.setmana(manaperso2-2*vraisacrifice); nbmana=nbmana-vraisacrifice; }else{perso2.setmana(0); nbmana=nbmana-vraisacrifice;}
    }

    void NightElf::sagessedelanature(){    //l'elfe communie avec la nature, cela augmente toutes ses caracteristiques.
          nbmana=nbmana-10;
          int nbechange=rand()%5;
    cout<< name +" communie avec la nature, cela augmente toutes ses caracteristiques. "<<endl;
          nbatta=nbatta+nbechange;
          nbdef=nbdef+nbechange;
          nbprec=nbprec+nbechange;
          nbagil=nbagil+nbechange;
    }

int NightElf::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour drain de mana(10), 2 pour sacrifice de mana, 3 pour sagesse de la nature(10)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour drain de mana(10), 2 pour sacrifice de mana, 3 pour sagesse de la nature(10)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<10){return 1;}
         else{
    draindemana(perso2);
          return 0;}
    }
    case 2:
   {

        sacrificemana(perso2);
            return 0;


    }
    case 3:
   {
        if (nbmana<10){return 1;}
         else{
        sagessedelanature();
            return 0;}
    }
}
}


void NightElf::attaque(Personnage &perso2)
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
NightElf::~NightElf(){}


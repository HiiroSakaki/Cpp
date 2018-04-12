#include "Troll.h"
using namespace std;

Troll::Troll():Personnage(){}

Troll::Troll(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Troll::affiche()
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

void Troll::berserker(){    //Le troll se transforme en berserker assoife de sang!!

    cout<< name + " se transforme en berserker !!!"<<endl;
    nbmana=nbmana-10;
    if (nbdef<10){nbdef=0;}else{nbdef=nbdef-10;}
    if (nbagil<10){nbagil=0;}else{nbagil=nbagil-10;}
    nbatta=nbatta+10;
    nbprec=nbprec+10;

        }

void Troll::regeneration(){    //la fois du paladin lui ajoute force et precision!!
    cout<<  name +" se regenere!!! "<<endl;
    nbmana=nbmana-10;
    nbvie=nbvie+rand()%20;
    }

    void Troll::armedejet(){    //Le troll n'utilise plus que des armes de jet, il va etre plus difficile a atteindre

    cout<< name + " utilise des armes de jet !!!"<<endl;
    nbmana=nbmana-10;
    if (nbatta<10){nbatta=0;}else{nbatta=nbatta-10;}
    if (nbdef<10){nbdef=0;}else{nbdef=nbdef-10;}
    nbagil=nbagil+10;
    nbprec=nbprec+10;
    }

int Troll::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour berserker(10), 2 pour regeneration(10), 3 pour arme de jet(10)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour berserker(10), 2 pour regeneration(10), 3 pour arme de jet(10)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1:    {
        if (nbmana<10){return 1;}
         else{
            berserker();
            return 0;}


    }
    case 2:
   {
        if (nbmana<10){return 1;}
         else{
            regeneration();
            return 0;}


    }
    case 3:
   {
        if (nbmana<10){return 1;}
         else{
            armedejet();
            return 0;}


    }
}
}


void Troll::attaque(Personnage &perso2)
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
Troll::~Troll(){}


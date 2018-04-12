#include "Gobelin.h"
using namespace std;

Gobelin::Gobelin():Personnage(){}

Gobelin::Gobelin(int vie, int mana, int atta, int def, int agil, int prec, string nom): Personnage(vie, mana, atta, def, agil, prec, nom){}



void Gobelin::affiche()
{

cout<<"Nom: "<<name<<endl;
cout<<"Race: Gobelin"<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

void Gobelin::explosion(Personnage &perso2){    //le gobelin engendre une terrible explosion!!
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    cout<<"Point de vie de "+name +":   "<<nbvie<<endl;
    cout<< name + " fait tout exploser !!!!! "<<endl;
    nbmana=nbmana-30;
    int vieperso2=perso2.getvie();
    int degat1=rand()%40;
    int degat2=rand()%20;
    if (degat1<vieperso2){perso2.setvie(vieperso2-degat1);}else{perso2.setvie(0);}
    if (degat2<nbvie){nbvie=nbvie-degat2;}else{nbvie=0;}
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    cout<<"Point de vie de "+name +":   "<<nbvie<<endl;
        }

void Gobelin::zeppelin(){    //le gobelin est bien plus vif a bord de son zeppelin!!
    cout<<  name +" est bien plus vif a bord de son zeppelin! "<<endl;
    nbmana=nbmana-10;
    nbagil=nbagil+rand()%20;
    }

    void Gobelin::apprentichimiste(){    //le gobelin boit des potions qui sont censees ameliorer ses caracteristiques mais il n'a pas l'air de tout maitriser.
          int nbmana=nbmana-20;
    cout<<  name +" boit une potion que va t il se passer??? "<<endl;
    int manapotion=rand()%20-8;
    cout<<"Mana de la potion : "<<manapotion<<endl;
    if (nbmana+manapotion<0){nbmana=0;}else {nbmana=nbmana+manapotion;}
    int viepotion=rand()%20-8;
    cout<<"Vie de la potion : "<<viepotion<<endl;
    if (nbvie+viepotion<0){nbvie=0;}else {nbvie=nbvie+viepotion;}
    int attapotion=rand()%20-8;
    cout<<"Attaque de la potion : "<<attapotion<<endl;
    if (nbatta+attapotion<0){nbatta=0;}else {nbatta=nbatta+attapotion;}
    int defpotion=rand()%20-8;
    cout<<"Defense de la potion : "<<defpotion<<endl;
    if (nbdef+defpotion<0){nbdef=0;}else {nbdef=nbdef+defpotion;}
    int agilpotion=rand()%20-8;
    cout<<"Agilite de la potion : "<<agilpotion<<endl;
    if (nbagil+agilpotion<0){nbagil=0;}else {nbagil=nbagil+agilpotion;}
    int precpotion=rand()%20-8;
    cout<<"Precision de la potion : "<<precpotion<<endl;
    if (nbprec+precpotion<0){nbprec=0;}else {nbprec=nbprec+precpotion;}

    }

int Gobelin::coupspecial(Personnage &perso2){

    cout<<"Choisissez votre coup special: 1 pour explosion(30), 2 pour zeppelin(10), 3 pour apprenti chimiste(20)"<<endl;
    int numerodesort;
    cin >> numerodesort;
        while ((3-numerodesort)*(2-numerodesort)*(1-numerodesort)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Choisissez votre coup special: 1 pour explosion(30), 2 pour zeppelin(10), 3 pour apprenti chimiste(20)"<<endl;
    cin >> numerodesort;
        }


switch (numerodesort)
{
     case 1: {
         if (nbmana<30){return 1;}
         else{
    explosion(perso2);
          return 0;}
    }
    case 2:
   {
        if (nbmana<10){return 1;}
         else{
            zeppelin();
            return 0;}


    }
    case 3:
   {
        if (nbmana<20){return 1;}
         else{
            apprentichimiste();
            return 0;}


    }
}
}


void Gobelin::attaque(Personnage &perso2)
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
Gobelin::~Gobelin(){}


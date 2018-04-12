#include "Combat.h"
#include <cstdlib>
#include <iostream>
using namespace std;

Combat::Combat(Personnage &personne1, Personnage &personne2): perso1(personne1),perso2(personne2){

}// avec perso1=personne1 ca ne marche pas car il copie avec le constructeur de personnage du coup il recopie un personnage
// toutes les fonctions appelees par la suite sont des personnages et pas des humains...


void Combat::Combatamort(){
    cout<<"debut du combat a mort"<<"\n"<<endl;

            cout<<perso1.getnom()+" "<<perso1.getvie()<<" "<<perso1.getmana()<<" "<<endl;
               cout<<perso2.getnom()<<" "<<perso2.getvie()<<" "<<perso2.getmana()<<"\n"<<endl;
                perso1.attaque(perso2);

                            cout<<perso1.getnom()+" "<<perso1.getvie()<<" "<<perso1.getmana()<<" "<<endl;
               cout<<perso2.getnom()<<" "<<perso2.getvie()<<" "<<perso2.getmana()<<"\n"<<endl;
                perso2.attaque(perso1);
        while(perso1.getvie() * perso2.getvie() !=0 )
            {

                perso1.setmana(perso1.getmana()+1);
                perso2.setmana(perso2.getmana()+1);
            cout<<perso1.getnom()+" "<<perso1.getvie()<<" "<<perso1.getmana()<<" "<<endl;
               cout<<perso2.getnom()<<" "<<perso2.getvie()<<" "<<perso2.getmana()<<" "<<endl;
                perso1.attaque(perso2);
                if (perso2.getvie()!=0){

                   cout<<perso1.getnom()<<" "<<perso1.getvie()<<" "<<perso1.getmana()<<" "<<endl;
                   cout<<perso2.getnom()<<" "<<perso2.getvie()<<" "<<perso2.getmana()<<" "<<endl;
                    perso2.attaque(perso1);}
            }

if (perso2.getvie()==0){

    cout<<perso1.getnom() + " a vaincu "+perso2.getnom()<<endl;} else {cout<<perso2.getnom()+" a vaincu "+perso1.getnom()<<endl;


    }

}

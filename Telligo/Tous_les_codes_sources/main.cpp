#include <iostream>
#include "Combat.h"
#include "BloodElf.h"
#include "Gnome.h"
#include "Gobelin.h"
#include "Humain.h"
#include "Nain.h"
#include "NightElf.h"
#include "Orc.h"
#include "Tauren.h"
#include "Troll.h"
#include "Undead.h"
#include <vector>

using namespace std;

int main()
{
vector<Personnage*> listepersonnage;





cout<<"Premier joueur choisissez le nom de votre personnage."<<endl;
string nom1;
cin>>nom1;
cout<<"Vous avez choisi "+nom1<<endl;
int choix=11;
while ((choix-1)*(choix-2)*(choix-3)*(choix-4)*(choix-5)*(choix-6)*(choix-7)*(choix-8)*(choix-9)*(choix-10)!=0){
cout<<"Quelle race de personnage souhaitez vous choisir??"<<endl;
cout<<"1 pour BloodElf"<<"\n"<<"2 pour Gnome"<<"\n"<<"3 pour Gobelin"<<"\n"<<"4 pour Humain"<<"\n"<<"5 pour Nain"<<"\n"<<"6 pour NightElf"<<"\n"<<"7 pour Orc"<<"\n"<<"8 pour Tauren"<<"\n"<<"9 pour Troll"<<"\n"<<"10 pour Undead"<<endl;
cin>>choix;

}

switch (choix)
{
    case 1: {
        listepersonnage.push_back(new BloodElf(100,100,100,100,100,100,nom1));
        break;
    }
    case 2:
   {
        listepersonnage.push_back(new Gnome(100,100,100,100,100,100,nom1));
        break;
    }
    case 3: {
        listepersonnage.push_back(new Gobelin(100,100,100,100,100,100,nom1));
        break;
    }
    case 4:
   {
        listepersonnage.push_back(new Humain(100,100,100,100,100,100,nom1));
        break;
    }
    case 5: {
        listepersonnage.push_back(new Nain(100,100,100,100,100,100,nom1));
        break;
    }
    case 6:
   {
        listepersonnage.push_back(new NightElf(100,100,100,100,100,100,nom1));
        break;
    }
    case 7: {
        listepersonnage.push_back(new Orc(100,100,100,100,100,100,nom1));
        break;
    }
    case 8:
   {
        listepersonnage.push_back(new Tauren(100,100,100,100,100,100,nom1));
        break;
    }
    case 9: {
        listepersonnage.push_back(new Troll(100,100,100,100,100,100,nom1));
        break;
    }
    case 10:
   {
        listepersonnage.push_back(new Undead(100,100,100,100,100,100,nom1));
        break;
    }
}




cout<<"Deuxieme joueur choisissez le nom de votre personnage."<<endl;
cin>>nom1;
cout<<"Vous avez choisi "+nom1<<endl;
choix=11;
while ((choix-1)*(choix-2)*(choix-3)*(choix-4)*(choix-5)*(choix-6)*(choix-7)*(choix-8)*(choix-9)*(choix-10)!=0){
cout<<"Quelle race de personnage souhaitez vous choisir??"<<endl;
cout<<"1 pour BloodElf"<<"\n"<<"2 pour Gnome"<<"\n"<<"3 pour Gobelin"<<"\n"<<"4 pour Humain"<<"\n"<<"5 pour Nain"<<"\n"<<"6 pour NightElf"<<"\n"<<"7 pour Orc"<<"\n"<<"8 pour Tauren"<<"\n"<<"9 pour Troll"<<"\n"<<"10 pour Undead"<<endl;
cin>>choix;
}

switch (choix)
{
    case 1: {
        listepersonnage.push_back(new BloodElf(100,100,100,100,100,100,nom1));
        break;
    }
    case 2:
   {
        listepersonnage.push_back(new Gnome(100,100,100,100,100,100,nom1));
        break;
    }
    case 3: {
        listepersonnage.push_back(new Gobelin(100,100,100,100,100,100,nom1));
        break;
    }
    case 4:
   {
        listepersonnage.push_back(new Humain(100,100,100,100,100,100,nom1));
        break;
    }
    case 5: {
        listepersonnage.push_back(new Nain(100,100,100,100,100,100,nom1));
        break;
    }
    case 6:
   {
        listepersonnage.push_back(new NightElf(100,100,100,100,100,100,nom1));
        break;
    }
    case 7: {
        listepersonnage.push_back(new Orc(100,100,100,100,100,100,nom1));
        break;
    }
    case 8:
   {
        listepersonnage.push_back(new Tauren(100,100,100,100,100,100,nom1));
        break;
    }
    case 9: {
        listepersonnage.push_back(new Troll(100,100,100,100,100,100,nom1));
        break;
    }
    case 10:
   {
        listepersonnage.push_back(new Undead(100,100,100,100,100,100,nom1));
        break;
    }
}

    Combat battleroyal(*listepersonnage[0],*listepersonnage[1]);
    battleroyal.Combatamort();
    return 0;
}

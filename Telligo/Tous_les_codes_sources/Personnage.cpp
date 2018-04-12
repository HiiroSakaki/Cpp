#include "Personnage.h"
#include <cstdlib>
using namespace std;





Personnage::Personnage() : nbvie(100),nbmana(100),nbatta(100),nbdef(100),nbagil(100),nbprec(100),name("")
{

}
Personnage::Personnage(int vie,int mana,int atta,int def,int agil,int prec, string nom)
{
nbvie=vie;
nbmana=mana;
nbatta=atta;
nbdef=def;
nbagil=agil;
nbprec=prec;
name=nom;
}
void Personnage::affiche()
{
cout<<"Nom: "<<name<<endl;
cout<<"Vie: "<<nbvie<<endl;
cout<<"Mana: "<<nbmana<<endl;
cout<<"Attaque: "<<nbatta<<endl;
cout<<"Defense: "<<nbdef<<endl;
cout<<"Agilite: "<<nbagil<<endl;
cout<<"Precision: "<<nbprec<<endl;

}

int Personnage::getvie()
{
return nbvie;
}
void Personnage::setvie(int vie)
{
nbvie=vie;
}
int Personnage::getmana()
{
return nbmana;
}
void Personnage::setmana(int mana)
{
nbmana=mana;
}
int Personnage::getatta()
{
return nbatta;
}
void Personnage::setatta(int atta)
{
nbatta=atta;
}
int Personnage::getdef()
{
return nbdef;
}
void Personnage::setdef(int def)
{
nbdef=def;
}
int Personnage::getagil()
{
return nbagil;
}
void Personnage::setagil(int agil)
{
nbagil=agil;
}
int Personnage::getprec()
{
return nbprec;
}
void Personnage::setprec(int prec)
{
nbprec=prec;
}

string Personnage::getnom()
{
return name;
}
void Personnage::setnom(string nom)
{
name=nom;
}

void Personnage::attaque(Personnage &perso2)
{
    cout<<"\n"<<"Que voulez vous faire: 1 pour attaquer, 2 pour coup special on est dans perso"<<endl;
    int choix;
    cin >> choix;
    while ((2-choix)*(1-choix)!=0){
    cout<<"choix invalide"<<endl;
    cout<<"Que voulez vous faire: 1 pour attaquer, 2 pour coup special choupinoua"<<endl;
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
        coupspecial(perso2);
    }
}
}

void Personnage::fight(Personnage &perso2)
{
    if (perso2.getvie()==0){       cout<<perso2.getnom()+" est deja mort!! "<<endl;} else {
    int precperso1=rand()%10 + nbprec; //reste de rand() qui va de 0 a randmax par la division euclidienne par 10
    int agilperso2=rand()%10 + perso2.getagil();
    if (precperso1<agilperso2) {  cout<<name<<" a rate son attaque"<<endl;      } else {
    int attaperso1=rand()%10 + nbatta;
    cout<<"\n"<<"Attaque de " + name +":   "<<attaperso1<<endl;
    int defperso2=rand()%10 + perso2.getdef();
    cout<<"Defense de "+perso2.getnom()  +":   "<<defperso2<<endl;
    int pvperso2=perso2.getvie();
    cout<<"Point de vie de "+perso2.getnom() +":   "<<pvperso2<<endl;
    if (attaperso1<=defperso2){perso2.setvie(pvperso2-1);
    cout<<name +" a fait 1 de dommage a "+perso2.getnom()<<endl;
    cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
    }
   else{
        if (pvperso2-attaperso1+defperso2<0){perso2.setvie(0);} else {perso2.setvie(pvperso2-attaperso1+defperso2);}
            cout<<name+" a fait "<< attaperso1-defperso2<< " de dommage a "+perso2.getnom()<<endl;
            cout<<"Point de vie de "+perso2.getnom() +":   "<<perso2.getvie()<<endl;
            }

    }
    }

}
int Personnage::coupspecial(Personnage &perso2){}

Personnage::~Personnage(){}





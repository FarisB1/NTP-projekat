#include <iostream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <functional>
#include "naruci.h"
#include "login.h"
using namespace std;

void meni(struct tipovi korpa[100],struct cijene cijenaPoVelicini[12],char ime[12][100],int cijenePriloga[4],double udaljenost)
{
	int i=0,c=1,j=0,prviIzbor,cijena[24]={4,6,8,5,7,9,5,7,9,4,6,8,6,8,10,8,10,12,6,8,10,8,10,12},ukupnaCijena=0,a[10];
 char name[20];
 
 for(i=0;i<12;i++)
 {
  korpa[i].mala=0;
  korpa[i].srednja=0;
  korpa[i].velika=0;
  korpa[i].suhoMeso=0;
  korpa[i].dodatniSir=0;
  korpa[i].masline=0;
  korpa[i].ostalo=0;

 }
 i=0;
 while(i<24)
 {
  cijenaPoVelicini[j].cijenaMala=cijena[i++];
  cijenaPoVelicini[j].cijenaSrednja=cijena[i++];
  cijenaPoVelicini[j].cijenaVelika=cijena[i++];
  cijenaPoVelicini[j].cijenaSuhoMeso=3;
  cijenaPoVelicini[j].cijenaMasline=3;
  cijenaPoVelicini[j].cijenaDodatniSir=4;
  j++;
 }
 do{
  if(c==1){
   cout<<"MENI\n1 - Burger\n2 - Pizza\n3 - Prilozi\n4 - Izlaz\n";
         cin>>prviIzbor;
   switch(prviIzbor)
   {
    case 1:
    {
     int drugiIzbor;
     cout<<"MENI\n1 - Classic Burger\n2 - Cheeseburger\n3 - Mexico Burger\n4 - Chicken\n5 - Exit\n";
     cin>>drugiIzbor;
     if(drugiIzbor!=5)
	 {
	      int velicinaIzbor;
	              cout<<"Unesite velicinu\n1 - Mala\n2 - Srednja\n3 - Velika\n";
	              cin>>velicinaIzbor;
	      if(velicinaIzbor==1)
	       korpa[drugiIzbor-1].mala++;
	      if(velicinaIzbor==2)
	                   korpa[drugiIzbor-1].srednja++;
	         if(velicinaIzbor==3)
	       korpa[drugiIzbor-1].velika ++;
	      if(drugiIzbor!=5)
	      cout<<"Burger uspjesno dodan.\n";
     }

     break;
     }
    case 2:
    {
     int drugiIzbor;
     cout<<"Unesite\n1 - Margeritha\n2 - Mexicana\n3 - Capricciosa\n4 - Quattro formaggi\n5 - Exit\n";
     cin>>drugiIzbor;
     if(drugiIzbor!=5){
      int velicinaIzbor;
              cout<<"Unesite velicinu\n1 - Mala\n2 - Srednja\n3 - Velika\n";
              cin>>velicinaIzbor;
      if(velicinaIzbor==1)
       korpa[drugiIzbor+4-1].mala++;
      if(velicinaIzbor==2)
                   korpa[drugiIzbor+4-1].srednja++;
         if(velicinaIzbor==3)
       korpa[drugiIzbor+4-1].velika ++;
      cout<<"Dodaci za pizzu:\n1 - Suho meso\n2 - Masline\n3 - Dodatni sir\n4 - Nista\n";
      int dodatak;
      cin>>dodatak;
      if(dodatak==1)
      korpa[drugiIzbor+4-1].suhoMeso++;
      else if(dodatak==2)
      korpa[drugiIzbor+4-1].masline++;
      else if(dodatak==3)
      korpa[drugiIzbor+4-1].dodatniSir++;
      if(drugiIzbor!=5)
      cout<<"Pizza uspjesno dodana.\n";
     }

     break;
    }
    case 3:
    {
     int drugiIzbor;
     cout<<"Izaberite prilog:\n1 - Pomfrit\n2 - Pekarski Krompir\n3 - Salata\n4 - Riza\n5 - Exit\n";
     cin>>drugiIzbor;
     if(drugiIzbor<5 && drugiIzbor>0)
         korpa[drugiIzbor+8-1].ostalo++;
        if(drugiIzbor!=5)
      cout<<"Prilog uspjesno dodan.\n";
     break;
     }
     
     case 4:
     	{
     		return;
		 }
     default:
     {
      cout<<"Pogresan izbor\n";
      break;
     }
     }
  }
  if(c==2)
  {
   int id,pizzaBrojac,dodatakBrojac,br,wrongIdFlag=1;
   cout<<"Classic Burger (0) \tCheeseburger (1) \tMexico Burger (2)\nChicken (3) \t\tMargeritha (4) \t\tMexicana (5)\nCapricciosa (6) \tQuattro formaggi (7) \tPomfrit (8)\nPekarski krompir (9) \tSalata (10) \t\tRiza (11)\n";
   cout<<"Unesite ID zeljenog proizvoda kako bi promijenili njegovu kolicinu:\n";
   cin>>id;
   if(id>=0 && id<=11)
   {
    if(id>=0&&id<=7)
    {
     if(korpa[i].mala >0||korpa[i].srednja >0||korpa[i].velika ||korpa[i].ostalo>0||korpa[i].suhoMeso >0||korpa[i].masline ||korpa[i].dodatniSir >0){
      cout<<"Unesite koju velicinu zelite promijeniti: \n1 -Mala\n2 -Srednja\n3 -Velika\n4 - Izlaz\n";
      cin>>pizzaBrojac;
      cout<<"Enter kolicinu koju zelite (da izbrisete unesite 0)\n";
      cin>>br;
      if(br>=0){
          if(pizzaBrojac==1)
          korpa[id].mala=br;
          if(pizzaBrojac==2)
          korpa[id].srednja=br;
          if(pizzaBrojac==3)
          korpa[id].velika=br;
      }
      else{
       cout<<"Unesite broj jednak ili veci od nule\n";
      }
     }
     else{
      cout<<"ID nije pronadjen\n";
      wrongIdFlag=0;
     }
    }
    else{
     cout<<"Enter\n1 - Pomfrit\n2 - Pekarski krompir\n3 - Salata\n4 - Riza\n5 - To Change Kolicina of  - Exit\n";
     cin>>pizzaBrojac;
     if(pizzaBrojac>=1 && pizzaBrojac<=4)
     {
      cout<<"Unesite kolicinu\n";
      cin>>br;
      korpa[id].ostalo=br;
     }

    }
    if(wrongIdFlag==1)
    {
                   cout<<"Kolicina uspjesno promjenjena\nVasa narudzba:\n";
                   naruci(korpa,cijenaPoVelicini,ime,cijenePriloga,udaljenost);
    }

   }
   else{
    cout<<"Unesite validan ID\n";
   }
  }
  if(c==4)
  {
   int id;
   naruci(korpa,cijenaPoVelicini,ime,cijenePriloga,udaljenost);
   cout<<"Unesite ID artikla kojeg zelite izbrisati iz korpe\n";
   cin>>id;
   korpa[id].mala =0;
   korpa[id].srednja =0;
   korpa[id].velika =0;
   korpa[id].ostalo=0;
   korpa[id].suhoMeso =0;
   korpa[id].masline =0;
   korpa[id].dodatniSir =0;
    cout<<"Artikal uspjesno izbrisan iz vase korpe\nVasa narudzba:\n";
     naruci(korpa,cijenaPoVelicini,ime,cijenePriloga,udaljenost);
  }
  if(c==3)
  {
   naruci(korpa,cijenaPoVelicini,ime,cijenePriloga,udaljenost);
   
  }
  system("pause");
  system("cls");
      cout<<"Enter\n1 - Dodajte artikal\n2 - Promjena kolicine\n3 - Korpa\n4 - Izbrisati iz korpe\nBilo koji drugi broj za kraj programa\n";
      cin>>c;
 }while(c==1 || c==2 || c==3 || c==4);
}



int main()
{
	int i=0,c=1,j=0,prviIzbor,cijena[24]={4,6,8,5,7,9,5,7,9,4,6,8,6,8,10,8,10,12,6,8,10,8,10,12},ukupnaCijena=0,a[10];
 char name[20];
 char ime[12][100]={
  "Classic Burger",
  "Cheeseburger",
  "Mexico Burger",
  "Chicken",
  "Margeritha",
  "Mexicana",
  "Capricciosa",
  "Quattro formaggi",
  "Pomfrit",
  "Pekarski krompir",
  "Salata",
  "Riza"
 };
 int cijenePriloga[4]={3,4,6,4};

 struct tipovi korpa[100];
 struct cijene cijenaPoVelicini[12];
 for(i=0;i<12;i++)
 {
  korpa[i].mala=0;
  korpa[i].srednja=0;
  korpa[i].velika=0;
  korpa[i].suhoMeso=0;
  korpa[i].dodatniSir=0;
  korpa[i].masline=0;
  korpa[i].ostalo=0;

 }
 i=0;
 while(i<24)
 {
  cijenaPoVelicini[j].cijenaMala=cijena[i++];
  cijenaPoVelicini[j].cijenaSrednja=cijena[i++];
  cijenaPoVelicini[j].cijenaVelika=cijena[i++];
  cijenaPoVelicini[j].cijenaSuhoMeso=3;
  cijenaPoVelicini[j].cijenaMasline=3;
  cijenaPoVelicini[j].cijenaDodatniSir=4;
  j++;
 }
	double dg = 0.3;
  	double gg = 6;
  	srand(time(NULL));
  	rand();
  	double udaljenost = dg + (gg - dg) * (rand() / (RAND_MAX + 1.0));
	prviMeni();
	meni(korpa,cijenaPoVelicini,ime,cijenePriloga,udaljenost);
	system("cls");
	naruci(korpa, cijenaPoVelicini, ime, cijenePriloga, udaljenost);
	save(korpa, cijenaPoVelicini, ime, cijenePriloga, udaljenost);
	cout<<"\nHvala.\n";
}

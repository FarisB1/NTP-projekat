#include <iostream>
using namespace std;
void naruci(struct tipovi korpa[100],struct cijene cijenaPoVelicini[12],char ime[12][100],int cijenePriloga[4],double udaljenost);
struct tipovi{
 int mala,srednja,velika,ostalo,suhoMeso,masline,dodatniSir;
};
struct cijene{
 int cijenaMala,cijenaSrednja,cijenaVelika,cijenaSuhoMeso,cijenaMasline,cijenaDodatniSir;
};


void naruci(struct tipovi korpa[100],struct cijene cijenaPoVelicini[12],char ime[12][100],int cijenePriloga[4],double udaljenost)
{
 int ukupnaCijena=0;
 cout<<"-----------------------------KORPA-----------------------------\n";
 for(int i=0;i<=11;i++)
 {
  if(korpa[i].mala >0||korpa[i].srednja >0||korpa[i].velika ||korpa[i].ostalo>0||korpa[i].suhoMeso >0||korpa[i].masline ||korpa[i].dodatniSir >0)
  {
   if(i>=0&&i<=7){
   cout<<"\nID : "<<i<<endl;
      cout<<"Ime Proizvoda : "<<ime[i]<<endl;
    if(korpa[i].mala >0)
	cout << "Mala velicina: " << korpa[i].mala << " -> Cijena: " << korpa[i].mala * cijenaPoVelicini[i].cijenaMala << endl;
    if (korpa[i].srednja > 0)
    cout << "Srednja velicina: " << korpa[i].srednja << " -> Cijena: " << korpa[i].srednja * cijenaPoVelicini[i].cijenaSrednja << endl;
	if (korpa[i].velika > 0)
    cout << "Velika velicina: " << korpa[i].velika << " -> Cijena: " << korpa[i].velika * cijenaPoVelicini[i].cijenaVelika << endl;
	if (korpa[i].suhoMeso > 0)
    cout << "Suho meso kolicina: " << korpa[i].suhoMeso << " -> Cijena: " << korpa[i].suhoMeso * cijenaPoVelicini[i].cijenaSuhoMeso << endl;
	if (korpa[i].dodatniSir > 0)
    cout << "Dodatni sir kolicina: " << korpa[i].dodatniSir << " -> Cijena: " << korpa[i].dodatniSir * cijenaPoVelicini[i].cijenaDodatniSir << endl;
	if (korpa[i].masline > 0)
    cout << "Masline kolicina: " << korpa[i].masline << " -> Cijena: " << korpa[i].masline * cijenaPoVelicini[i].cijenaMasline << endl ;

   ukupnaCijena+=korpa[i].mala*cijenaPoVelicini[i].cijenaMala;
   ukupnaCijena+=korpa[i].srednja*cijenaPoVelicini[i].cijenaSrednja;
   ukupnaCijena+=korpa[i].velika*cijenaPoVelicini[i].cijenaVelika;
   ukupnaCijena+=korpa[i].suhoMeso*cijenaPoVelicini[i].cijenaSuhoMeso;
   ukupnaCijena+=korpa[i].masline*cijenaPoVelicini[i].cijenaMasline;
   ukupnaCijena+=korpa[i].dodatniSir*cijenaPoVelicini[i].cijenaDodatniSir;
  }
  else{
   cout<<"\nID : "<<i<<endl;
   cout<<"Ime Proizvoda : "<<ime[i]<<endl;
   cout<<"Kolicina : "<<korpa[i].ostalo<<endl;
   cout<<"Cijena : "<<korpa[i].ostalo*cijenePriloga[i-8]<<endl;
   ukupnaCijena+=(korpa[i].ostalo)*cijenePriloga[i-8];
  }
 }
  }
  
 
  double cijenaDostave = udaljenost *1.5;
   cout<<"-------------------Udaljenost : "<<setprecision(3)<<udaljenost<<" km -----------------------\n";
   cout<<"-------------------Cijena Dostave : "<<setprecision(3)<<cijenaDostave<<" KM -------------------\n";
   cout<<"-------------------Ukupna Cijena : "<<setprecision(3)<<ukupnaCijena+cijenaDostave<<" KM --------------------\n";
}



void save(struct tipovi korpa[100], struct cijene cijenaPoVelicini[12], char ime[12][100], int cijenePriloga[4], double udaljenost) {
    ofstream file("narudzbe.txt",ios::app);
    double ukupnaCijena;
	if (file.is_open()) {
        for (int i = 0; i <= 11; i++) {
            if (korpa[i].mala > 0 || korpa[i].srednja > 0 || korpa[i].velika || korpa[i].ostalo > 0 || korpa[i].suhoMeso > 0 || korpa[i].masline || korpa[i].dodatniSir > 0) {
                if (i >= 0 && i <= 7) {
                    file << "\nID : " << i << endl;
                    file << "Ime Proizvoda : " << ime[i] << endl;
                    if (korpa[i].mala > 0)
                        file << "Mala velicina: " << korpa[i].mala << " -> Cijena: " << korpa[i].mala * cijenaPoVelicini[i].cijenaMala << endl;
                    if (korpa[i].srednja > 0)
                        file << "Srednja velicina: " << korpa[i].srednja << " -> Cijena: " << korpa[i].srednja * cijenaPoVelicini[i].cijenaSrednja << endl;
                    if (korpa[i].velika > 0)
                        file << "Velika velicina: " << korpa[i].velika << " -> Cijena: " << korpa[i].velika * cijenaPoVelicini[i].cijenaVelika << endl;
                    if (korpa[i].suhoMeso > 0)
                        file << "Suho meso kolicina: " << korpa[i].suhoMeso << " -> Cijena: " << korpa[i].suhoMeso * cijenaPoVelicini[i].cijenaSuhoMeso << endl;
                    if (korpa[i].dodatniSir > 0)
                        file << "Dodatni sir kolicina: " << korpa[i].dodatniSir << " -> Cijena: " << korpa[i].dodatniSir * cijenaPoVelicini[i].cijenaDodatniSir << endl;
                    if (korpa[i].masline > 0)
                        file << "Masline kolicina: " << korpa[i].masline << " -> Cijena: " << korpa[i].masline * cijenaPoVelicini[i].cijenaMasline << endl;

                    ukupnaCijena += korpa[i].mala * cijenaPoVelicini[i].cijenaMala;
                    ukupnaCijena += korpa[i].srednja * cijenaPoVelicini[i].cijenaSrednja;
                    ukupnaCijena += korpa[i].velika * cijenaPoVelicini[i].cijenaVelika;
                    ukupnaCijena += korpa[i].suhoMeso * cijenaPoVelicini[i].cijenaSuhoMeso;
                    ukupnaCijena += korpa[i].masline * cijenaPoVelicini[i].cijenaMasline;
                    ukupnaCijena += korpa[i].dodatniSir * cijenaPoVelicini[i].cijenaDodatniSir;
                }
                else {
                    file << "\nID : " << i << endl;
                    file << "Ime Proizvoda : " << ime[i] << endl;
                    file << "Kolicina : " << korpa[i].ostalo << endl;
                    file << "Cijena : " << korpa[i].ostalo * cijenePriloga[i - 8] << endl;
                    ukupnaCijena += (korpa[i].ostalo) * cijenePriloga[i - 8];
                }
            }
        }

        double cijenaDostave = udaljenost * 1.5;
        file << "-------------------Udaljenost : " << setprecision(3) << udaljenost << " km -----------------------\n";
        file << "-------------------Cijena Dostave : " << setprecision(3) << cijenaDostave << " KM -------------------\n";
        file << "-------------------Ukupna Cijena : " << setprecision(3) << ukupnaCijena + cijenaDostave << " KM --------------------\n";
        file << "\n\n_______________________________________________________________________________________________\n\n";

        file.close();
    }
}



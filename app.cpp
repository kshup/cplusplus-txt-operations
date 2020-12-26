#include <iostream>
#include <fstream>
#include<string> 
using namespace std;




class Musteri {
   public:
      string ad,soyad ,sorguTC;; 
		double borc,alacak,bakiye;
	   unsigned long long int tc;

     
void ekleme(){
	   ofstream dosya1("hesap.txt",ios::out | ios::app);
	   string ad,soyad; 
	   double borc,alacak,bakiye;
	   unsigned long long int tc;
  
        cout << "tc giriniz :" << endl;
        cin >> tc;
        cout << "Ad giriniz :" << endl;
        cin >> ad;
        cout << "soyAdinizi giriniz :" << endl;
        cin >> soyad;
        cout << "borc giriniz :" << endl;
        cin >> borc;
        cout << "alacak giriniz :" << endl;
        cin >> alacak;
        
        
        dosya1<< endl;
        dosya1<<tc;
        dosya1 << " ";
        dosya1<<ad;
        dosya1 << " ";
        dosya1<<soyad;
        dosya1 << " ";
        dosya1<<borc;
        dosya1 << " ";
        dosya1<<alacak;
        dosya1 << " ";
        bakiye = borc-alacak;
        dosya1<<bakiye;
        dosya1 << " ";
        
}
void silme(){
string line, tc;
cout << "Silmek istediginiz kisinin tc sini giriniz: ";
cin >> tc;
ifstream dosya;
dosya.open("hesap.txt");
ofstream temp;
temp.open("temp.txt");
while (getline(dosya, line))
{
if (line.substr(0, tc.size()) != tc)
temp << line << endl;
}
cout << "Girdiginiz tc " << tc << " kayitlarimizda bulunuyor ise silindi." << endl;
dosya.close();
temp.close();
remove("hesap.txt");
rename("temp.txt", "hesap.txt");



}

void Listele(){
	ifstream dosyaOku("hesap.txt");
  string satir = "";

  if ( dosyaOku.is_open() ){

    while ( getline(dosyaOku, satir) ){
      cout << satir << endl;
    }

    dosyaOku.close();
  }

}

void arama(){
string tcc,sorgu;
string ad,soyad; 
double borc,alacak,bakiye;	

cout << "Sorgula:"; cin >> sorgu;
 

ifstream DosyaOku("hesap.txt");
while (!(DosyaOku.eof()))
{
DosyaOku >> tcc >> ad >> soyad >> borc >>alacak >> bakiye;

if ( tcc == sorgu )
{

cout << " Tc :" << tcc << endl;
cout << " Adi :" << ad << endl;
cout << " Soyadi : " << soyad << endl;
cout << " Borc:  :" << borc << endl;
cout << " Alacak :" << alacak << endl;
cout << "Bakiye :" << borc-alacak << "\n";
 
DosyaOku.close();
break;
}

if ( sorgu == ad )
{
cout << " Tc :" << tcc << endl;
cout << " Adi :" << ad << endl;
cout << " Soyadi : " << soyad << endl;
cout << " Borc:  :" << borc << endl;
cout << " Alacak :" << alacak << endl;
cout << "Bakiye :" << borc-alacak << "\n";
 
DosyaOku.close();
break;
}
if ( sorgu == soyad )
{
cout << " Tc :" << tcc << endl;
cout << " Adi :" << ad << endl;
cout << " Soyadi : " << soyad << endl;
cout << " Borc:  :" << borc << endl;
cout << " Alacak :" << alacak << endl;
cout << "Bakiye :" << borc-alacak << "\n";
 
DosyaOku.close();
break;
}

}
}

void toplambakiye(){
unsigned long long int tc;
string ad,soyad; 
double borc,alacak,bakiye,toplambakiye=0;	
ifstream DosyaOku("hesap.txt");
double toplam = 0;


while (!DosyaOku.eof())
{
DosyaOku >> tc >> ad >> soyad >> borc >>alacak >> bakiye;
toplambakiye+=bakiye;	

}

cout << "Toplam Bakiye = " << toplambakiye-bakiye << endl;
DosyaOku.close();
}
void guncelle(){
string g_TC;
string ad,soyad,tc; 
double borc,alacak,bakiye,gbakiye;	
ifstream DosyaOku("hesap.txt"); 
ofstream GeciciDosyaYaz("hesap.tmp");

cout << "Tc'yi giriniz"<< endl;
cin >> g_TC;
 
while (DosyaOku >>tc >> ad >> soyad >> borc >>alacak >> bakiye)
{
if (g_TC != tc)
GeciciDosyaYaz << tc << " " << ad << " " << soyad << " " << borc << " " << alacak << " " << bakiye << "\n";
 
if (g_TC==tc)
{
cout << "\n Guncelleme \n";
cout << "\n TC :"; cin >> tc;
cout << "\n AD :"; cin >> ad;
cout << "\n Soyad :"; cin >> soyad;
cout << "\n borc :"; cin >> borc;
cout << "\n Alacak :"; cin >> alacak;
gbakiye = borc-alacak;

 
GeciciDosyaYaz << tc << " " << ad << " " << soyad << " " << borc  <<  " " << alacak  <<  " " << gbakiye  <<  "\n"; 

}
}
GeciciDosyaYaz.close();
DosyaOku.close();
 
remove("hesap.txt"); 
rename("hesap.tmp", "hesap.txt"); 
}
      
};



int main(){
  
Musteri Musteri1;



while(true){
int islem;
cout << "1- Listeleme:" << endl;
cout << "2- Ekleme:" << endl;
cout << "3- Sil:" << endl;
cout << "4- Guncelle:" << endl;
cout << "5- Ara:" << endl;
cout << "6- toplamBakiye:" << endl;
cout << "7- Cikis:" << endl;
cin >> islem;	

if (islem==1) {
Musteri1.Listele();
continue;
}

else if (islem==2){
	Musteri1.ekleme();
	continue;
}
else if (islem==3){
	Musteri1.silme();
	continue;
}
else if (islem==4){
	Musteri1.guncelle();
	continue;
}
else if (islem==5){
	Musteri1.arama();
	continue;
}
else if (islem == 6){
Musteri1.toplambakiye();
continue;
}

else if(islem==7){
	break; 
}

}
 
  return 0;
}

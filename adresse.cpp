#include "adresse.h"
#include<iostream>
#include <iomanip>

using namespace std;


Adresse::Adresse(double l, double b, string str, int hnr, int _plz, string gmde)
    :Ort(l, b), strasse(str), hausnummer(hnr), plz(_plz), gemeinde(gmde){
    Ort::setIsPol(false);
}

Adresse::Adresse(int _id,double l, double b, string str, int hnr, int _plz, string gmde)
    :Ort(_id, l, b), strasse(str), hausnummer(hnr), plz(_plz), gemeinde(gmde){
    Ort::setIsPol(false);
}


Adresse::~Adresse()
{

}

string Adresse::getStrasse() const
{
    return strasse;
}

void Adresse::setStrasse(const string &newStrasse)
{
    strasse = newStrasse;
}

int Adresse::getHausnummer() const
{
    return hausnummer;
}

void Adresse::setHausnummer(int newHausnummer)
{
    hausnummer = newHausnummer;
}

int Adresse::getPlz() const
{
    return plz;
}

void Adresse::setPlz(const int &newPlz)
{
    plz = newPlz;
}

string Adresse::getGemeinde() const
{
    return gemeinde;
}

void Adresse::setGemeinde(const string &newGemeinde)
{
    gemeinde = newGemeinde;
}

void Adresse::anzeigen()
{
    cout <<setw(8)<<Adresse::getId()<<" | " << setw(10) << Adresse::getLarngengrad() << " | "<<setw(10) << Adresse::getBreitengrad()<< " | " <<setw(35)
    <<strasse<<" "<<hausnummer<<", "<<plz<<" "<< gemeinde<<endl<<  endl;
}


















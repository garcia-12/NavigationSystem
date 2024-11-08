#include "pol.h"
#include <iostream>
#include <iomanip>

using namespace std;
Pol::Pol(double l, double b, string k, string bem)
    :Ort(l, b), kategorie(k), bemerkung(bem){
    Ort::setIsPol(true);
}

Pol::Pol(int _id, double l, double b, string k, string bem)
    :Ort(_id, l, b), kategorie(k), bemerkung(bem){
    Ort::setIsPol(true);
}

Pol::~Pol()
{

}

string Pol::getKategorie() const
{
    return kategorie;
}

void Pol::setKategorie(const string &newKategorie)
{
    kategorie = newKategorie;
}

string Pol::getBemerkung() const
{
    return bemerkung;
}

void Pol::setBemerkung(const string &newBemerkung)
{
    bemerkung = newBemerkung;
}

void Pol::anzeigen()
{
    cout << setw(8) << Pol::getId() << " | " << setw(10) << Pol::getLarngengrad() << " | " << setw(10) << Pol::getBreitengrad() << " | "
         <<setw(35) << Pol::getKategorie() <<" | "<< setw(35) << Pol::getBemerkung()<<endl;
}

#ifndef ADRESSE_H
#define ADRESSE_H

#include "ort.h"
#include <string>

using namespace std;

class Adresse: public Ort
{
public:
    Adresse(double l, double b, string str, int hnr, int _plz, string gmde);
    Adresse(int _id, double l, double b, string str, int hnr, int _plz, string gmde);
    virtual ~Adresse();
    string getStrasse() const;
    void setStrasse(const string &newStrasse);

    int getHausnummer() const;
    void setHausnummer(int newHausnummer);

    int getPlz() const;
    void setPlz(const int &newPlz);

    string getGemeinde() const;
    void setGemeinde(const string &newGemeinde);

    virtual void anzeigen() override;

private:
    string strasse;
    int hausnummer;
    int plz;
    string gemeinde;
};

#endif // ADRESSE_H

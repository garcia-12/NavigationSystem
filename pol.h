#ifndef POL_H
#define POL_H

#include "ort.h"
#include <string>

using namespace std;

class Pol: public Ort
{
public:
    Pol(double l, double b, string k, string bem);
    Pol(int _id, double l, double b, string k, string bem);
    virtual ~Pol();
    string getKategorie() const;
    void setKategorie(const string &newKategorie);

    string getBemerkung() const;
    void setBemerkung(const string &newBemerkung);

    virtual void anzeigen() override;

private:
    string kategorie;
    string bemerkung;
};

#endif // POL_H

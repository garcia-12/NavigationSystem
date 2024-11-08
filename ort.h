#ifndef ORT_H
#define ORT_H

class Ort
{
public:
    Ort(double _lang, double _breite);
    Ort(int _id, double _lang, double _breite);
    virtual ~Ort();

    virtual  void anzeigen() = 0;
    double getLarngengrad() const;
    void setLarngengrad(double newLarngengrad);
    double getBreitengrad() const;
    void setBreitengrad(double newBreitengrad);
    double BerechnungEntfernnung(/*const*/ Ort*& zielOrt);

    bool getIsPol() const;
    void setIsPol(bool newIsPol);

    static int getNextId();
    static void setNextId(int newNextId);

    int getId() const;

private:
    double laengengrad;
    double breitengrad;
    bool isPol = true;
    const int id = Ort::nextId;
    static int nextId;
};

#endif // ORT_H

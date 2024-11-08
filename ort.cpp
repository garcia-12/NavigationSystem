#include "ort.h"
#include <cmath>

int Ort::nextId = 1;

Ort::Ort(double _lang, double _breite)
    :laengengrad(_lang), breitengrad(_breite){
    Ort::nextId++;
}

Ort::Ort(int _id,double _lang, double _breite)
    :id(_id), laengengrad(_lang), breitengrad(_breite){

}



Ort::~Ort()
{

}

double Ort::getLarngengrad() const
{
    return laengengrad;
}

void Ort::setLarngengrad(double newLarngengrad)
{
    laengengrad = newLarngengrad;
}

double Ort::getBreitengrad() const
{
    return breitengrad;
}

void Ort::setBreitengrad(double newBreitengrad)
{
    breitengrad = newBreitengrad;
}

double Ort::BerechnungEntfernnung(Ort *&zielOrt)
{
    const int R= 6371;//in Km
    const double PI = 3.14159265358979323846;
    const double IN_GRAD_CONVERT = PI/180;
    double dx, dy;
    dx = (zielOrt->getBreitengrad() - this->getBreitengrad());
    dy = (zielOrt->getLarngengrad() - this->getLarngengrad());



    return 2*R*asin(sqrt((sin((dx*IN_GRAD_CONVERT)/2))*(sin((dx*IN_GRAD_CONVERT)/2)) +
                             cos((zielOrt->getBreitengrad())*IN_GRAD_CONVERT)*cos(((this->getBreitengrad()))*IN_GRAD_CONVERT)*(sin((dy*IN_GRAD_CONVERT)/2))*(sin((dy*IN_GRAD_CONVERT)/2))));
}

bool Ort::getIsPol() const
{
    return isPol;
}

void Ort::setIsPol(bool newIsPol)
{
    isPol = newIsPol;
}

int Ort::getNextId()
{
    return nextId;
}

void Ort::setNextId(int newNextId)
{
    nextId = newNextId;
}

int Ort::getId() const
{
    return id;
}

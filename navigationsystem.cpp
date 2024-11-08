#include "navigationsystem.h"
#include "adresse.h"
#include "pol.h"
#include <iomanip>
#include<iostream>
#include <string>
#include <sstream> //für String in datei
#include <fstream>

using namespace std;

NavigationSystem::NavigationSystem() {}

NavigationSystem::~NavigationSystem()
{
    for(unsigned int i = 0; i < orte.size(); i++){
        delete orte[i];
    }

    orte.clear();
    cout << "Bis BAld!"<<endl;
}

void NavigationSystem::display(vector <Ort*>& ort)
{
    cout <<"### Adresse ###" <<endl<<endl;

    cout << setw(8)<< "Id"
         <<" | " << setw(10)<< "Laengegrad"
         <<" | " << setw(10) << "Breitegrad"
         <<" | " << setw(35)<< "Adresse"
         <<endl;

    cout << setfill('-') << setw(120) << "-" <<endl;
    cout << setfill(' ');
    for(auto& ort:ort){
        Adresse* adr = dynamic_cast<Adresse*>(ort);
        if (adr)
            adr->anzeigen();
    }

    cout <<endl<<endl;

    cout << "### Pol ###"<<endl<<endl<<endl;

    cout << setw(8)<< "Id"
         <<" | " << setw(10)<< "Laengegrad"
         <<" | " << setw(10) << "Breitegrad"
         <<" | " << setw(35)<< "Kategorie"
         <<" | " << setw(35)<< "Bemerkung"
         <<endl;

    cout << setfill('-') << setw(120) << "-" <<endl;
    cout << setfill(' ');
    for (auto& ort: ort){
        Pol* pol = dynamic_cast<Pol*>(ort);
        if(pol)
            pol->anzeigen();
    }
}

// void NavigationSystem::displayPol(vector<Ort *> ort)
// {
//     cout << setw(8)<< "Id"
//          <<" | " << setw(10)<< "Laengegrad"
//          <<" | " << setw(10) << "Breitegrad"
//          <<" | " << setw(15)<< "Kategorie"
//          <<" | " << setw(15)<< "Bemerkung"
//          <<endl;

//     cout << setfill('-') << setw(120) << "-" <<endl;
//     cout << setfill(' ');
//     for (auto& ort: ort){
//         // Pol* pol = dynamic_cast<Pol*>(ort);
//         // if(pol)
//             ort->anzeigen();
//     }
// }

Ort *NavigationSystem::ortFinden(const int &id)
{
    for(auto& ort: orte){
        if(ort->getId() == id)
            return ort;
    }

    return nullptr;
}

void NavigationSystem::orteLaden(vector<Ort *> &orte, const string &map)
{
    ifstream file(map);
    if(!file){
        cout << "Fehler beim Laden"<<endl;
        return;
    }

    string line;
    bool isPolSection = false;
    int checkId = 1;
    while(getline(file, line)){
        if(line[0] == 'P'){
            isPolSection = true;
            continue;
        }

        if(line.empty())
            continue;

        istringstream stream(line);
        if(!isPolSection){
            string strasse, gemeinde, laenge_str, breite_str, hausnummer_str, plz_str, id_str;
            double laenge, breite;
            int hausnummer, plz, id;
            if(getline(stream, id_str, ';') and getline(stream, laenge_str, ';') and getline(stream, breite_str, ';') and getline(stream, strasse, ';') and getline(stream, hausnummer_str, ';') and getline(stream, plz_str, ';')
                and getline(stream, gemeinde, ';')){

                id_str = id_str.substr(0, id_str.find_last_not_of(" \t")+ 1);
                id = stoi(id_str);

                laenge_str = laenge_str.substr(0, laenge_str.find_last_not_of(" \t") + 1);
                laenge = stod(laenge_str);

                breite_str = breite_str.substr(0, breite_str.find_last_not_of(" \t") + 1);
                breite = stod(breite_str);

                hausnummer_str = hausnummer_str.substr(0, hausnummer_str.find_last_not_of(" \t") + 1);
                hausnummer = stoi(hausnummer_str);

                plz_str = plz_str.substr(0, plz_str.find_last_not_of(" \t") + 1);
                plz = stoi(plz_str);

                strasse = strasse.substr(0, strasse.find_last_not_of(" \t") + 1);
                gemeinde = gemeinde.substr(0, gemeinde.find_last_not_of(" \t") + 1);

                if(!strasse.empty() and strasse[0] == ' '){
                    strasse.erase(0, 1);
                }
                if (!gemeinde.empty() and gemeinde[0] == ' '){
                    gemeinde.erase(0, 1);
                }

                Adresse* newAd = new Adresse(id, laenge, breite, strasse, hausnummer, plz, gemeinde);
                // newAd->anzeigen();
                orte.push_back(newAd);

                if(checkId < id)
                    checkId = id;
            }
        }
        else{
            string laenge_str, breite_str, id_str, bemerkung, kategorie ;
            double laenge, breite;
            int id;
            if(getline(stream, id_str, ';') and getline(stream, laenge_str, ';') and getline(stream, breite_str, ';') and getline(stream, kategorie, ';') and getline(stream, bemerkung, ';')){


                id_str = id_str.substr(0, id_str.find_last_not_of(" \t")+ 1);
                id = stoi(id_str);

                laenge_str = laenge_str.substr(0, laenge_str.find_last_not_of(" \t") + 1);
                laenge = stod(laenge_str);

                breite_str = breite_str.substr(0, breite_str.find_last_not_of(" \t") + 1);
                breite = stod(breite_str);

                kategorie = kategorie.substr(0, kategorie.find_last_not_of(" \t") + 1);
                bemerkung = bemerkung.substr(0, bemerkung.find_last_not_of(" \t") + 1);

                if(!kategorie.empty() and kategorie[0] == ' '){
                    kategorie.erase(0, 1);
                }
                if (!bemerkung.empty() and bemerkung[0] == ' '){
                    bemerkung.erase(0, 1);
                }

                Pol* newPol = new Pol(id, laenge, breite, kategorie, bemerkung);
                // newPol->anzeigen();
                orte.push_back(newPol);

                if(checkId < id)
                    checkId = id;
            }
        }

    }
    cout <<"Map erfplgreich geladen"<<endl;
    Ort::setNextId(checkId+1);
    file.close();
}

void NavigationSystem::orteSpeichern(vector<Ort *> &orte, const string &map)
{
    ofstream file(map);
    if(!file){
        cout << "Fehler bei Schreiben"<<endl;
        return;
    }

    file<<"Adresse l ; b"<<endl;
    for(auto& ort: orte){
        Adresse* adr = dynamic_cast<Adresse*>(ort);
        if (adr){
            file <<adr->getId()<<"; " << adr->getLarngengrad() <<"; "<< adr->getBreitengrad()<< "; "<<adr->getStrasse()
            <<"; "<< adr->getHausnummer()<<"; "<< adr->getPlz() << "; "<<adr->getGemeinde()<<endl;
        }
    }

    file<<"Pol"<<endl;
    for(auto& ort: orte){
        Pol* pol = dynamic_cast<Pol*>(ort);
        if(pol){
            file <<pol->getId()<<"; " << pol->getLarngengrad()<<"; "<< pol->getBreitengrad()<<"; "<< pol->getKategorie()<<"; "
                 <<pol->getBemerkung()<<endl;
        }

    }

    cout << "Map erfolgreich gesichert!" <<endl;
    file.close();
}


void NavigationSystem::dialog()
{
    char eingabe;

    double laenge, breite;
    string strasse,gemeinde, kategorie, bemerkung;
    int hausnummer, plz;
    while(true){
        cout << "********** NavigationSystem **********"<<endl;
        cout << "(1) Ort anlegen"<<endl;
        cout << "(2) Karte anzeigen"<<endl;
        cout << "(3) Entfernung berechnen"<<endl;
        cout << "(4) Karte speichern/laden"<<endl;
        cout << "(0) Pragramm verlassen"<<endl;

        cin >> eingabe;

        switch (eingabe) {
            //anlegen
        case '1':{
            char unterEingage;
            cout << "(a) Adresse"<<endl;
            cout << "(b) Pol"<<endl;
            cin >> unterEingage;

            switch (unterEingage) {
            case 'a':{
                cout << "Laengengrad: "; cin >> laenge;
                cout <<"Breitengrad: "; cin >> breite;

                cout << "Strasse: ";
                cin.ignore(10, '\n');
                getline(cin, strasse);

                cout << "Hausnummer: "; cin>> hausnummer;
                cout <<"Postleitzahl: "; cin >> plz;

                cout << "Gemeinde: ";
                cin.ignore(10, '\n');
                getline(cin, gemeinde);

                Adresse* newAdresse = new Adresse(laenge,  breite, strasse, hausnummer, plz, gemeinde);
                orte.push_back(newAdresse);
                cout << "Erfolgreich angelgt!"<<endl;

            }
            break;

            case 'b':{
                cout << "Laengengrad: "; cin >> laenge;
                cout <<"Breitengrad: "; cin >> breite;

                cout << "Kategorie: ";
                cin.ignore(10, '\n');
                getline(cin, kategorie);

                cout << "Bemerkung: ";
                // cin.ignore(10, '\n');
                getline(cin, bemerkung);

                Pol* newPol = new Pol(laenge, breite, kategorie, bemerkung);
                orte.push_back(newPol);
                cout << "Erfolgreich angelgt!"<<endl;

            }
            break;
            default:
                break;
            }

            // char unterEingage;
            // cout << "(a) Adresse"<<endl;
            // cout << "(b) Pol"<<endl;
            // cin >> unterEingage;

            // switch (unterEingage) {
            // case 'a':{

                // }
                // break;

            // case 'b':{

                // }
                // break;
                // default:
                //     break;
                // }

        }
        break;
        //anzeigen
        case '2':{
            display(orte);
            // cout << "### Pol ###"<<endl<<endl<<endl;
            // displayPol(orte);
        }
        break;

        case '3':{
            display(orte);
            int ab, an;
            cout <<"Nummer der AbfarhtOrt: "; cin>> ab;
            cout << "Nummer des Ziels: "; cin>>an;

            Ort* abOrt = ortFinden(ab);
            Ort* anOrt = ortFinden(an);
            if(abOrt == nullptr or anOrt == nullptr){
                cout << "Bitte waehlen Sie nur Ort, die verfuegbar sind!!!"<<endl;
            }
            else{
                cout << "Die Entfernung: " << abOrt->BerechnungEntfernnung(anOrt)<<" Km"<<endl;
            }

        }
            break;
        case '4':{
            char unterEingage;
            cout << "(a) Laden"<<endl;
            cout << "(b) Speichern"<<endl;
            cin >> unterEingage;

            switch (unterEingage) {
            case 'a':{
                for(unsigned int i = 0; i < orte.size(); i++){
                    delete orte[i];
                }

                orte.clear();

                orteLaden(orte, "map.txt");

            }
            break;

            case 'b':{
                orteSpeichern(orte, "map.txt");
            }
            break;
            default:
                break;
            }

        }
        break;
        case '0':
            return;
        default:
            break;
        }
    }
}





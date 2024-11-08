#ifndef NAVIGATIONSYSTEM_H
#define NAVIGATIONSYSTEM_H
#include "ort.h"
#include <string>
#include <vector>

using namespace std;

class NavigationSystem
{
public:
    NavigationSystem();
    ~NavigationSystem();
    void dialog();
    void display(vector <Ort*>& ort);
    // void displayPol(vector<Ort*> ort);
    Ort* ortFinden(const int& id);
    void orteLaden(vector <Ort*>& orte, const string& map);
    void orteSpeichern(vector <Ort*>& orte, const string& map);
private:
    vector <Ort*> orte;
};

#endif // NAVIGATIONSYSTEM_H


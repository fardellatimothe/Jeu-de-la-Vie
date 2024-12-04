#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observers.h"

using namespace std;

class Observable {

protected:
    vector<Observer*> list_observers;

public:
    void ajouterObservateurs(Observer* observer);
    virtual void notifierObservateur(int x, int y, int etat) = 0;
};

#endif

#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observers.h"

using namespace std;

class Observable {

private:
    vector<Observer*> list_observers;

public:
    void ajouterObservateurs(Observer* observer);
    virtual void notifierObservateurs(int x, int y, bool etat);

};

#endif

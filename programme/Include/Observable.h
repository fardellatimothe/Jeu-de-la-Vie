#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include "Observers.h"

using namespace std;

class Observable {

protected:
    vector<Observer*> list_observers;

public:
    void AjtObservateurs(Observer* observer);
    virtual void NotifObservateur(int x, int y, int etat) = 0;
};

#endif

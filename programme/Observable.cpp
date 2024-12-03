#include "Observable.h"

#include <iostream>
using namespace std;

void Observable::notifierObservateurs(int x, int y, bool etat) {
    for (auto observer : list_observers) {
        observer->update(x, y, etat);
    }
}

void Observable::ajouterObservateurs(Observer* observer) {
    list_observers.push_back(observer);
}
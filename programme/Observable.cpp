#include "Observable.h"

#include <iostream>
using namespace std;

void Observable::ajouterObservateurs(Observer* observer) {
    list_observers.push_back(observer);
}
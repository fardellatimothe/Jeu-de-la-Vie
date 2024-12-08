#include "Observable.h"

#include <iostream>
using namespace std;

void Observable::AjtObservateurs(Observer* observer) {
    list_observers.push_back(observer);
}
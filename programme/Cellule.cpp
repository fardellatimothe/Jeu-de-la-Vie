#include "Cellule.h"

Cellule::Cellule(int x, int y) : nbVoisinesVivantes(0), x(x), y(y) {}

void Cellule::setNbVoisinesVivantes(int nb) {
    nbVoisinesVivantes = nb;
}

void Cellule::notifierObservateurs(int x, int y, bool etat) {
    // Logique pour notifier les observateurs
}

int Cellule::getx() const {
    return x;
}

int Cellule::gety() const {
    return y;
}

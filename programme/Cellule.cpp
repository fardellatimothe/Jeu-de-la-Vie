#include "Cellule.h"

Cellule::Cellule(int x, int y) : nbVoisinesVivantes(0), x(x), y(y) {}

void Cellule::IncrementerVoisinesVivantes() {
    nbVoisinesVivantes = nbVoisinesVivantes + 1;
}

int Cellule::getx() const {
    return x;
}

int Cellule::gety() const {
    return y;
}

int Cellule::getVoisin() const {
    return nbVoisinesVivantes;
}
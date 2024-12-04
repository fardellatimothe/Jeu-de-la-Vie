#include "Cellule.h"

Cellule::Cellule(int x, int y) : nbVoisinesVivantes(0), x(x), y(y) {}

void Cellule::IncrementerVoisinesVivantes() {
    nbVoisinesVivantes++;
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

void Cellule::resetVoisin(){
    nbVoisinesVivantes = 0;
}
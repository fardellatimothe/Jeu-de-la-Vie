#include "Cellule.h"

Cellule::Cellule(int x, int y) : nb_voisines_vivantes(0), x(x), y(y) {}

void Cellule::IncrementerVoisinesVivantes() {
    nb_voisines_vivantes++;
}

int Cellule::GetX() const {
    return x;
}

int Cellule::GetY() const {
    return y;
}

int Cellule::GetVoisin() const {
    return nb_voisines_vivantes;
}

void Cellule::ResetVoisin(){
    nb_voisines_vivantes = 0;
}
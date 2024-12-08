#include "CelluleVivante.h"

CelluleVivante::CelluleVivante(int x, int y, bool obstacle) : Cellule(x, y), obstacle(obstacle) {}
CelluleVivante::CelluleVivante(int x, int y) : Cellule(x, y) {}


bool CelluleVivante::CalculerProchainEtat() {
    if (obstacle == true) return true;
    return (nb_voisines_vivantes == 2 || nb_voisines_vivantes == 3);
}

int CelluleVivante::Etat()const {
    return 1;
}
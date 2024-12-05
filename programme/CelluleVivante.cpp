#include "CelluleVivante.h"

CelluleVivante::CelluleVivante(int x, int y, bool obstacle) : Cellule(x, y), obstacle(obstacle) {}
CelluleVivante::CelluleVivante(int x, int y) : Cellule(x, y) {}


bool CelluleVivante::calculerProchainEtat() {
    if (obstacle == true) return true;
    return (nbVoisinesVivantes >= 2 && nbVoisinesVivantes <= 3);
}

int CelluleVivante::etat()const {
    return 1;
}
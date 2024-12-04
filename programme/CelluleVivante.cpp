#include "CelluleVivante.h"

CelluleVivante::CelluleVivante(int x, int y) : Cellule(x, y) {}

bool CelluleVivante::calculerProchainEtat() {
    return (nbVoisinesVivantes >= 2 && nbVoisinesVivantes <= 3);
}

int CelluleVivante::etat()const {
    return 1;
}
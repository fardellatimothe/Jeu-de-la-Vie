#include "CelluleVoisine.h"

CelluleVoisine::CelluleVoisine(int x, int y) : Cellule(x, y) {}

bool CelluleVoisine::calculerProchainEtat() {
    return (nbVoisinesVivantes == 3);
}

int CelluleVoisine::etat()const {
    return 0;
}


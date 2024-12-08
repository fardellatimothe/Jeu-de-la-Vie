#include "CelluleVoisine.h"

CelluleVoisine::CelluleVoisine(int x, int y) : Cellule(x, y) {}

bool CelluleVoisine::CalculerProchainEtat() {
    return (nb_voisines_vivantes == 3);
}

int CelluleVoisine::Etat()const {
    return 0;
}


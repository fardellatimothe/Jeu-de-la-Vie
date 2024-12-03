#include "CelluleVoisine.h"

CelluleVoisine::CelluleVoisine(int x, int y) : Cellule(x, y) {}

bool CelluleVoisine::calculerProchainEtat(int voisin) {
    return (voisin == 3);
}

void CelluleVoisine::notifierObservateurs(int x, int y, bool etat) {
    
}

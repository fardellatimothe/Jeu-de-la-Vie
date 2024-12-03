#include "CelluleVoisine.h"

CelluleVoisine::CelluleVoisine(int x, int y) : Cellule(x, y) {}

bool CelluleVoisine::estVivante() const {
    return false; // Logique pour vérifier si la cellule voisine est vivante
}

void CelluleVoisine::calculerProchainEtat() {
    // Logique de calcul de l'état suivant pour une cellule voisine
}

#include "CelluleVivante.h"

CelluleVivante::CelluleVivante(int x, int y) : Cellule(x, y) {}

bool CelluleVivante::calculerProchainEtat(int voisin) {
    return (voisin >= 2 && voisin <= 3);
}

void CelluleVivante::notifierObservateurs(int x, int y, bool etat) {
    
}
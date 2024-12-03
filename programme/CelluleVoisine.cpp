#include "CelluleVoisine.h"

CelluleVoisine::CelluleVoisine(int x, int y) : Cellule(x, y) {}

bool CelluleVoisine::calculerProchainEtat() {
    if (nbVoisinesVivantes == 3){
        notifierObservateurs(x, y, true);
        return true;
    } else {
        return false;
    }
}


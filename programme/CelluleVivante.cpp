#include "CelluleVivante.h"

CelluleVivante::CelluleVivante(int x, int y) : Cellule(x, y) {}

bool CelluleVivante::calculerProchainEtat() {
    if (nbVoisinesVivantes >= 2 && nbVoisinesVivantes <= 3){
        return true;
    } else {
        notifierObservateurs(x, y, false);
        return false;
    }
}
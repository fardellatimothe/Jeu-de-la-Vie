#include "Grille.h"

void Grille::initialiser(std::vector<std::vector<int>>& matrice) {
    for (int i = 0; i < matrice.size(); ++i) {
        for (int j = 0; j < matrice[i].size(); ++j) {
            if (matrice[i][j] == 1) {
                Cellule* cellule = new CelluleVivante(i, j);
                CelluleVivantePile.push(cellule);
            }
        }
    }
}


void Grille::calculerProchaineIteration() {
    // Logique de calcul de la prochaine itération
}

int Grille::TaillePile() {
    return CelluleVivantePile.size();
}

bool Grille::estStable() const {
    return true; // Logique pour vérifier si la grille est stable
}

#include "Grille.h"

Grille::Grille(vector<vector<int>>& matrice) {
    CelluleExiste.resize(matrice.size(), vector<Cellule*>(matrice[0].size(), nullptr));
    for (int i = 0; i < matrice.size(); ++i) {
        for (int j = 0; j < matrice[0].size(); ++j) {
            if (matrice[i][j] == 1) {
                Cellule* cellule = new CelluleVivante(i, j);
                CelluleVivantePile.push(cellule);
                CelluleExiste[i][j] = cellule;
            }
        }
    }
}

void Grille::calculerProchaineIteration() {
    CalculVoisin();
    CalculSurvie();
}

void Grille::CalculVoisin() {
    while (!CelluleVivantePile.empty()) {
        int x = CelluleVivantePile.top()->getx();
        int y = CelluleVivantePile.top()->gety();
        
        int hauteur = CelluleExiste.size(); // Nombre de lignes
        int largeur = CelluleExiste[0].size(); // Nombre de colonnes

        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                int newX = x + i;
                int newY = y + j;

                if (newX >= 0 && newX < hauteur && newY >= 0 && newY < largeur && !(i == 0 && j == 0)) {
                    if (CelluleExiste[newX][newY] == nullptr) {
                        Cellule* cellule_voisine = new CelluleVoisine(newX, newY);
                        cellule_voisine->IncrementerVoisinesVivantes();
                        CelluleTransition.push(cellule_voisine);
                        CelluleExiste[newX][newY] = cellule_voisine;
                    } else {
                        CelluleExiste[newX][newY]->IncrementerVoisinesVivantes();
                    }
                    
                }
            }
        }
        CelluleTransition.push(CelluleVivantePile.top());
        CelluleVivantePile.pop();
    }
}

void Grille::CalculSurvie(){
    while (!CelluleTransition.empty()){
        int nb_voisin = CelluleTransition.top()->getVoisin();
        int x = CelluleTransition.top()->getx();
        int y = CelluleTransition.top()->getx();

        if (CelluleTransition.top()->calculerProchainEtat(nb_voisin)){
            Cellule* cellule_vivante = new CelluleVivante(x, y);
            CelluleVivantePile.push(cellule_vivante);
            CelluleExiste[x][y] = cellule_vivante;

            delete CelluleTransition.top();
            CelluleTransition.pop();

        } else {
            CelluleExiste[x][y] = nullptr;
            delete CelluleTransition.top();
            CelluleTransition.pop();
        }
    }
}

int Grille::TaillePile() {
    return CelluleVivantePile.size();
}

bool Grille::estStable() const {
    return true; // Logique pour vérifier si la grille est stable
}

int Grille::nbVoisin(int x, int y){
    if (CelluleExiste[x][y] == nullptr){
        return 0;
    }
    return CelluleExiste[x][y]->getVoisin();
}

#include "Grille.h"

Grille::Grille(vector<vector<int>>& matrice, bool grille_torique) {
    this->grille_torique = grille_torique;
    existe_pile.resize(matrice.size(), vector<Cellule*>(matrice[0].size(), nullptr));
    for (size_t i = 0; i < matrice.size(); ++i) {
        for (size_t j = 0; j < matrice[0].size(); ++j) {
            if (matrice[i][j] == 1) {
                Cellule* cellule = new CelluleVivante(i, j);
                cell_vivante_pile.push(cellule);
                existe_pile[i][j] = cellule;
            } else if (matrice[i][j] == 2) {
                Cellule* cellule = new CelluleVivante(i, j, true);
                cell_vivante_pile.push(cellule);
                existe_pile[i][j] = cellule;
            } else if (matrice[i][j] == 3) {
                Cellule* cellule = new CelluleVoisine(i, j);
                existe_pile[i][j] = cellule;
            }            
        }
    }
}

void Grille::CalculerProchaineIteration() {
    stable = true;
    CalculVoisin();
    CalculSurvie();
}

void Grille::CalculVoisin() {
    while (!cell_vivante_pile.empty()) {
        int x = cell_vivante_pile.top()->GetX();
        int y = cell_vivante_pile.top()->GetY();
        
        int hauteur = existe_pile.size(); // Nombre de lignes
        int largeur = existe_pile[0].size(); // Nombre de colonnes
        for (int i = -1; i < 2; i++) {
            for (int j = -1; j < 2; j++) {
                
                int newX, newY
                ;
                if (grille_torique){
                    newX = (x + i + hauteur) % hauteur;
                    newY = (y + j + largeur) % largeur;
                } else {
                    newX = x + i;
                    newY = y + j;
                }

                if (newX >= 0 && newX < hauteur && newY >= 0 && newY < largeur && !(i == 0 && j == 0)) {
                    if (existe_pile[newX][newY] == nullptr) {
                        Cellule* cellule_voisine = new CelluleVoisine(newX, newY);
                        cellule_voisine->IncrementerVoisinesVivantes();
                        temp_pile.push(cellule_voisine);
                        existe_pile[newX][newY] = cellule_voisine;
                    } else {
                        existe_pile[newX][newY]->IncrementerVoisinesVivantes();
                    }
                    
                }
            }
        }
        temp_pile.push(cell_vivante_pile.top());
        cell_vivante_pile.pop();
    }
}

void Grille::CalculSurvie(){
    while (!temp_pile.empty()){
        int x = temp_pile.top()->GetX();
        int y = temp_pile.top()->GetY();
        
        if (temp_pile.top()->CalculerProchainEtat()){
            if (temp_pile.top()->Etat() == 1)
            {
                cell_vivante_pile.push(temp_pile.top());
                cell_vivante_pile.top()->ResetVoisin();
                temp_pile.pop();
                
            } else if (temp_pile.top()->Etat() == 0)
            {
                Cellule* cellule_vivante = new CelluleVivante(x, y);
                cell_vivante_pile.push(cellule_vivante);
                existe_pile[x][y] = cellule_vivante;
                NotifObservateur(x, y, 1);

                delete temp_pile.top();
                temp_pile.pop();
            }

        } else {
            if (temp_pile.top()->Etat() == 1)
            {
                existe_pile[x][y] = nullptr;
                NotifObservateur(x, y, 0);
                delete temp_pile.top();
                temp_pile.pop();
                
            } else if (temp_pile.top()->Etat() == 0)
            {   existe_pile[x][y] = nullptr;
                delete temp_pile.top();
                temp_pile.pop();
            }
        }
    }
}

int Grille::TaillePile() {
    return cell_vivante_pile.size();
}

bool Grille::EstStable() const {
    return stable;
}

int Grille::nb_voisin(int x, int y){
    if (existe_pile[x][y] == nullptr) return 0;
    return existe_pile[x][y]->GetVoisin();
}

void Grille::NotifObservateur(int x, int y, int Etat){
    stable = false;
    for (auto observer : list_observers) {
        observer->Update(x, y, Etat);
    }
}

void Grille::ModifCellule(int x, int y, int Etat){
    Cellule *cellule = existe_pile[x][y];
    if (Etat == 1 && cellule == nullptr){
        Cellule* nouvelle_cellule = new CelluleVivante(x, y);
        cell_vivante_pile.push(nouvelle_cellule);
        existe_pile[x][y] = nouvelle_cellule;

    } else if (Etat == 0 && cellule != nullptr)
    {
        std::stack<Cellule*> temp_pile;
        while (!cell_vivante_pile.empty()) {
            if (cell_vivante_pile.top() == cellule) {
                delete cell_vivante_pile.top();
                cell_vivante_pile.pop();
            } else {
                temp_pile.push(cell_vivante_pile.top());
                cell_vivante_pile.pop();
            }
        }
        while (!temp_pile.empty()){
            cell_vivante_pile.push(temp_pile.top());
            temp_pile.pop();
        }
    }
}
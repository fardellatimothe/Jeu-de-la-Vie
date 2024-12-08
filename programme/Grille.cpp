#include "Grille.h"

/**
 * @brief Constructeur de la classe Grille.
 *
 * Initialise la grille en créant les cellules à partir d'une matrice donnée. 
 * Les cellules vivantes ou voisines sont ajoutées à leurs structures respectives.
 *
 * @param matrice Référence vers une matrice représentant l'état initial de la grille 
 * (0 = vide, 1 = cellule vivante, 2 = cellule vivante persistante, 3 = cellule voisine).
 * @param grille_torique Indique si la grille est torique (true) ou non (false).
 */
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


/**
 * @brief Calcule l'état de la grille pour l'itération suivante.
 *
 * Cette méthode calcule les voisins de toutes les cellules vivantes et détermine 
 * leur état pour l'itération suivante, en appliquant les règles du jeu de la vie.
 */
void Grille::CalculerProchaineIteration() {
    stable = true;
    CalculVoisin();
    CalculSurvie();
}

/**
 * @brief Calcule les cellules voisines des cellules vivantes.
 *
 * Parcourt les cellules vivantes de la pile et met à jour les compteurs de voisins 
 * pour toutes les cellules voisines. Ajoute les nouvelles cellules voisines détectées 
 * à une pile temporaire.
 */
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


/**
 * @brief Met à jour l'état des cellules en fonction des règles du jeu.
 *
 * Détermine les cellules qui survivent, naissent ou meurent et met à jour la grille en conséquence.
 * Notifie les observateurs pour tout changement d'état des cellules.
 */
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


/**
 * @brief Retourne la taille de la pile des cellules vivantes.
 *
 * @return Le nombre de cellules vivantes actuellement dans la grille.
 */
int Grille::TaillePile() {
    return cell_vivante_pile.size();
}


/**
 * @brief Vérifie si la grille est stable.
 *
 * Une grille est stable si aucune cellule ne change d'état entre deux itérations successives.
 *
 * @return True si la grille est stable, False sinon.
 */
bool Grille::EstStable() const {
    return stable;
}


/**
 * @brief Compte le nombre de voisins vivants pour une cellule donnée.
 *
 * @param x Coordonnée en ligne de la cellule.
 * @param y Coordonnée en colonne de la cellule.
 * @return Le nombre de voisins vivants pour la cellule à la position donnée.
 */
int Grille::nb_voisin(int x, int y){
    if (existe_pile[x][y] == nullptr) return 0;
    return existe_pile[x][y]->GetVoisin();
}


/**
 * @brief Notifie les observateurs d'un changement d'état d'une cellule.
 *
 * Met à jour l'état de stabilité de la grille et appelle la méthode `Update` 
 * des observateurs enregistrés.
 *
 * @param x Coordonnée en ligne de la cellule modifiée.
 * @param y Coordonnée en colonne de la cellule modifiée.
 * @param Etat Nouvel état de la cellule (0 = morte, 1 = vivante).
 */
void Grille::NotifObservateur(int x, int y, int Etat){
    stable = false;
    for (auto observer : list_observers) {
        observer->Update(x, y, Etat);
    }
}


/**
 * @brief Modifie l'état d'une cellule spécifique dans la grille.
 *
 * Change l'état d'une cellule aux coordonnées données et met à jour la grille en conséquence.
 * Si la cellule devient vivante, elle est ajoutée à la pile des cellules vivantes.
 * Si elle devient morte, elle est retirée de la pile.
 *
 * @param x Coordonnée en ligne de la cellule.
 * @param y Coordonnée en colonne de la cellule.
 * @param Etat Nouvel état de la cellule (0 = morte, 1 = vivante).
 */
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
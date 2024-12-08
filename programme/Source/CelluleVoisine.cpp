#include "CelluleVoisine.h"


/**
 * @brief Constructeur de la classe CelluleVoisine.
 *
 * Initialise une cellule voisine avec ses coordonnées. Une cellule voisine 
 * est une cellule vide qui peut potentiellement devenir vivante.
 *
 * @param x Coordonnée en ligne de la cellule.
 * @param y Coordonnée en colonne de la cellule.
 */
CelluleVoisine::CelluleVoisine(int x, int y) : Cellule(x, y) {}


/**
 * @brief Calcule si une cellule voisine devient vivante à l'itération suivante.
 *
 * Une cellule voisine devient vivante si elle a exactement 3 voisins vivants.
 *
 * @return True si la cellule devient vivante, False sinon.
 */
bool CelluleVoisine::CalculerProchainEtat() {
    return (nb_voisines_vivantes == 3);
}


/**
 * @brief Obtient l'état de la cellule voisine.
 *
 * Une cellule voisine est toujours considérée comme morte, donc son état est 0.
 *
 * @return 0, indiquant que la cellule est morte.
 */
int CelluleVoisine::Etat()const {
    return 0;
}


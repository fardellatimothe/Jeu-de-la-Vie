#include "CelluleVivante.h"

/**
 * @brief Constructeur de la classe CelluleVivante avec obstacle.
 *
 * Initialise une cellule vivante avec ses coordonnées et un indicateur 
 * d'obstacle (cellule immuable).
 *
 * @param x Coordonnée en ligne de la cellule.
 * @param y Coordonnée en colonne de la cellule.
 * @param obstacle Indique si la cellule est un obstacle (true) ou non (false).
 */
CelluleVivante::CelluleVivante(int x, int y, bool obstacle) : Cellule(x, y), obstacle(obstacle) {}


/**
 * @brief Constructeur de la classe CelluleVivante sans obstacle.
 *
 * Initialise une cellule vivante avec ses coordonnées. Par défaut, 
 * cette cellule n'est pas un obstacle.
 *
 * @param x Coordonnée en ligne de la cellule.
 * @param y Coordonnée en colonne de la cellule.
 */
CelluleVivante::CelluleVivante(int x, int y) : Cellule(x, y) {}


/**
 * @brief Calcule si la cellule vivante survivra à l'itération suivante.
 *
 * Une cellule vivante reste en vie si elle a exactement 2 ou 3 voisins vivants.
 * Si la cellule est un obstacle, elle reste vivante indépendamment du nombre 
 * de voisins.
 *
 * @return True si la cellule survit à l'itération suivante, False sinon.
 */
bool CelluleVivante::CalculerProchainEtat() {
    if (doit_mourir == true) return false;
    if (obstacle == true) return true;
    return (nb_voisines_vivantes == 2 || nb_voisines_vivantes == 3);
}


/**
 * @brief Obtient l'état de la cellule vivante.
 *
 * Une cellule vivante a toujours un état égal à 1.
 *
 * @return 1, indiquant que la cellule est vivante.
 */
int CelluleVivante::Etat()const {
    return 1;
}
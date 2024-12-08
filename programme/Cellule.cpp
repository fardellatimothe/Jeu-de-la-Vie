#include "Cellule.h"

/**
 * @brief Constructeur de la classe Cellule.
 *
 * Initialise une cellule avec ses coordonnées et un compteur de voisins vivants à 0.
 *
 * @param x Coordonnée en ligne de la cellule.
 * @param y Coordonnée en colonne de la cellule.
 */
Cellule::Cellule(int x, int y) : nb_voisines_vivantes(0), x(x), y(y) {}


/**
 * @brief Incrémente le nombre de voisins vivants de la cellule.
 *
 * Augmente de 1 le compteur de voisins vivants de cette cellule.
 */
void Cellule::IncrementerVoisinesVivantes() {
    nb_voisines_vivantes++;
}


/**
 * @brief Obtient la coordonnée en ligne de la cellule.
 *
 * @return La coordonnée en ligne de la cellule.
 */
int Cellule::GetX() const {
    return x;
}


/**
 * @brief Obtient la coordonnée en colonne de la cellule.
 *
 * @return La coordonnée en colonne de la cellule.
 */
int Cellule::GetY() const {
    return y;
}


/**
 * @brief Obtient le nombre de voisins vivants de la cellule.
 *
 * @return Le nombre de voisins vivants associés à cette cellule.
 */
int Cellule::GetVoisin() const {
    return nb_voisines_vivantes;
}


/**
 * @brief Réinitialise le compteur de voisins vivants de la cellule.
 *
 * Met le compteur de voisins vivants à 0.
 */
void Cellule::ResetVoisin(){
    nb_voisines_vivantes = 0;
}
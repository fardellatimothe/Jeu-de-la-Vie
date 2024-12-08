#include "Console.h"


/**
 * @brief Constructeur de la classe Console.
 *
 * Initialise une instance de la console qui agit comme un observateur de la matrice.
 *
 * @param grid Pointeur vers une matrice représentant la grille du jeu de la vie.
 */
Console::Console(vector<vector<int>>* grid) : matrice(grid) {}


/**
 * @brief Met à jour l'état d'une cellule dans la matrice.
 *
 * Cette méthode met à jour la valeur de la cellule située aux coordonnées 
 * spécifiées dans la matrice en fonction de son nouvel état.
 *
 * @param x Coordonnée en ligne de la cellule à mettre à jour.
 * @param y Coordonnée en colonne de la cellule à mettre à jour.
 * @param etat Nouvel état de la cellule (0 = morte, 1 = vivante).
 */
void Console::Update(int x, int y, int etat){
    matrice->at(x).at(y) = etat;
}


/**
 * @brief Affiche la matrice sur la console.
 *
 * Parcourt la matrice et imprime son contenu ligne par ligne. Chaque cellule est 
 * séparée par un espace, et chaque ligne est affichée sur une nouvelle ligne.
 */
void Console::AfficherMatrice() const {
    for (const auto& ligne : *matrice) {
        for (int val : ligne) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
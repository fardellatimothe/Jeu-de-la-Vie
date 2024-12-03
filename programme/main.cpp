#include "GestionFichier.h"

#include <iostream>

int main() {
    GestionFichier gestionFichier("fichier_input.txt");

    // Lire l'état initial
    gestionFichier.lireEtatInitial();

    // Afficher la matrice
    // std::cout << "Matrice lue depuis le fichier :\n";
    // gestionFichier.afficherMatrice();

    // Sauvegarder l'état actuel dans un autre fichier
    gestionFichier.sauvegarderEtat();

    return 0;
}

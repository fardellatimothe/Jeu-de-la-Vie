#include "GestionFichier.h"

#include <iostream>

int main() {
    GestionFichier gestionFichier("fichier_input.txt");

    // Lire l'état initial
    gestionFichier.lireEtatInitial();

    // Afficher la matrice
    std::cout << "Matrice lue depuis le fichier :\n";
    gestionFichier.afficherMatrice();

    // Sauvegarder l'état actuel dans un autre fichier
    gestionFichier.sauvegarderEtat();

    std::vector<std::vector<int>> maa(5, std::vector<int>(10, 1));
    std::vector<std::vector<int>> maaa(5, std::vector<int>(10, 2));

    gestionFichier.setMatrice(&maa);

    // Afficher la matrice
    std::cout << "\n\nMatrice mise manuellement :\n";
    gestionFichier.afficherMatrice();

    // Sauvegarder l'état actuel dans un autre fichier
    gestionFichier.sauvegarderEtat();

    // test

    gestionFichier.sauvegarderEtat(&maaa);

    // Afficher la matrice
    std::cout << "\n\nDeuxième matrice mise manuellement :\n";
    gestionFichier.afficherMatrice();

    return 0;
}

#include "GestionFichier.h"

#include <iostream>

int main() {
    GestionFichier gestionFichier("fichier_input.txt","Test");

    // Lire l'état initial
    gestionFichier.lireEtatInitial();

    std::vector<std::vector<int>> maa(5, std::vector<int>(10, 1));
    // std::vector<std::vector<int>> maaa(5, std::vector<int>(10, 2));

    // Sauvegarder l'état actuel dans un autre fichier
    gestionFichier.sauvegarderEtat(maa);

    // gestionFichier.sauvegarderEtat(maaa);

    return 0;
}

#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H

#include <iostream>
#include <string>
#include <vector>


class GestionFichier {
    private:
        std::string cheminInitialisation;
        std::string cheminSauvegarde;
        int x_grille;
        int y_grille;
        std::vector<std::vector<int>> matrice_grille;

    public: 
        GestionFichier(std::string path);
        GestionFichier(std::string path, std::string output);

        void lireEtatInitial();
        void sauvegarderEtat();

        ~GestionFichier();
};

#endif
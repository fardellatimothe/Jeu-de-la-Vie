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
        int ite;

    public: 
        GestionFichier(std::string path);
        GestionFichier(std::string path, std::string output);

        int getx();
        int gety();


        std::vector<std::vector<int>>* lireEtatInitial();
        void sauvegarderEtat(std::vector<std::vector<int>> matrice_grille);

        ~GestionFichier();
};

#endif
#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H

#include <iostream>
#include <string>
#include <vector>


class GestionFichier {
    private:
        std::string cheminSauvegarde;
        int x_grille;
        int y_grille;
        int ite;

    public: 
        GestionFichier();
        GestionFichier(std::string output);


        std::vector<std::vector<int>>* lireEtatInitial(std::string cheminInitialisation);
        void sauvegarderEtat(std::vector<std::vector<int>>* matrice_grille);

        ~GestionFichier();
};

#endif
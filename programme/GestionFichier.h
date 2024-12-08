#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GestionFichier {
    private:
        string chemin_sauvegarde;
        int x_grille;
        int y_grille;
        int ite;

    public: 
        GestionFichier();
        GestionFichier(string output);


        vector<vector<int>>* LireEtatInitial(string chemin_initialisation);
        void SauvegarderEtat(vector<vector<int>>* matrice_grille);

        ~GestionFichier();
};

#endif
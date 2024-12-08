#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "Observers.h"

#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class Graphique : public Observer {
    private:
        int taille_cellule;
        sf::RenderWindow jeu;
        double temp_vitesse;
        bool pause=false;
    public:
        Graphique(vector<vector<int>> &matrice);
        void Initialisation(vector<vector<int>> &matrice);
        void Update(int x, int y, int etat) override;
        bool Events(double *vitesse, bool *changement_cellule, int *x, int *y, int *etat);
        bool FenetreOuverte() const; // Méthode adaptée pour vérifier l'état de la fenêtre
        void AfficherGrille(const vector<vector<int>> &matrice); // Nouvelle méthode
        void UpdateGrille();
        ~Graphique() override;
};

#endif
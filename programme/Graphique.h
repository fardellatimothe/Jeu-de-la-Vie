#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "Observers.h"

#include <vector>
#include <SFML/Graphics.hpp>

class Graphique : public Observer {
    private:
        int taille_cellule;
        sf::RenderWindow jeu;
    public:
        Graphique(std::vector<std::vector<int>> &matrice);

        void initialiser(std::vector<std::vector<int>> &matrice);

        void update(int x, int y, int etat) override;

        void handleEvents();
        bool fenetreOuverte() const; // Méthode adaptée pour vérifier l'état de la fenêtre

        void afficherGrille(const std::vector<std::vector<int>> &matrice); // Nouvelle méthode

        ~Graphique() override;
};

#endif
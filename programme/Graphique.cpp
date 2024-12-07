#include "Graphique.h"

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>


#include "Graphique.h"
#include <iostream>


Graphique::Graphique(std::vector<std::vector<int>> &matrice) {
    int lignes = matrice.size();
    int colonnes = matrice[0].size();

    const int taille_fenetre_max = 800;
    taille_cellule = std::min(taille_fenetre_max / colonnes, taille_fenetre_max / lignes);

    // Taille minimale pour éviter que les cellules soient trop petites
    if (taille_cellule < 1) {
        taille_cellule = 1;
    }

    int largeur_fenetre = colonnes * taille_cellule;
    int hauteur_fenetre = lignes * taille_cellule;

    jeu.create(sf::VideoMode(largeur_fenetre, hauteur_fenetre), "Jeu de la Vie");
}



// Initialiser la grille
void Graphique::initialiser(std::vector<std::vector<int>> &matrice) {

    sf::RectangleShape cellule(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
    for (int x = 0; x < matrice.size(); ++x) {
        for (int y = 0; y < matrice[0].size(); ++y) {
            if (matrice[x][y] == 1) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::White);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 2)
            {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Green);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 3)
            {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Red);
                jeu.draw(cellule);
            }
        }
    }
    jeu.display();
}

// Afficher la grille à partir de la matrice
void Graphique::afficherGrille(const std::vector<std::vector<int>> &matrice) {

    int lignes = matrice.size();
    int colonnes = matrice[0].size();

    jeu.clear();

    sf::RectangleShape cellule(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
    for (int x = 0; x < lignes; ++x) {
        for (int y = 0; y < colonnes; ++y) {
            if (matrice[x][y] == 1) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::White);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 2)
            {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Green);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 3)
            {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Red);
                jeu.draw(cellule);
            }
        }
    }

    jeu.display();
}

// Mettre à jour une cellule dans la grille
void Graphique::update(int x, int y, int etat) {
    sf::RectangleShape cellule(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
    cellule.setPosition(y * taille_cellule, x * taille_cellule);
    cellule.setFillColor(etat == 1 ? sf::Color::White : sf::Color::Black);

    jeu.draw(cellule);
}

void Graphique::update_grille(){
    jeu.display();
}

// Gérer les événements de la fenêtre
void Graphique::handleEvents() {
    sf::Event event;
    while (jeu.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            jeu.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                jeu.close();
            }
        }
    }
}

void Graphique::detectionVitesse(double *vitesse) {
    sf::Event eventv;
    while (jeu.pollEvent(eventv)) {
        if (eventv.type == sf::Event::KeyPressed) {
            if (eventv.key.code == sf::Keyboard::Space) {
                jeu.close();
            } else if (eventv.key.code == sf::Keyboard::Up) {
                std::cout << "fleche haut";
                *vitesse+=0.1;
            } else if (eventv.key.code == sf::Keyboard::Down) {
                std::cout << "fleche bas";
                *vitesse-=0.1;
                
            }
        }
    }
}

// Vérifier si la fenêtre est ouverte
bool Graphique::fenetreOuverte() const {
    return jeu.isOpen(); // Vérifie si la fenêtre est toujours ouverte
}

// Destructeur
Graphique::~Graphique() {}
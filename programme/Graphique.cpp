#include "Graphique.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>



Graphique::Graphique(vector<vector<int>> &matrice) {
    int lignes = matrice.size();
    int colonnes = matrice[0].size();

    const int taille_fenetre_max = 800;
    taille_cellule = min(taille_fenetre_max / colonnes, taille_fenetre_max / lignes);

    // Taille minimale pour éviter que les cellules soient trop petites
    if (taille_cellule < 1) {
        taille_cellule = 1;
    }

    int largeur_fenetre = colonnes * taille_cellule;
    int hauteur_fenetre = lignes * taille_cellule;

    jeu.create(sf::VideoMode(largeur_fenetre, hauteur_fenetre), "Jeu de la Vie");
}



// Initialiser la grille
void Graphique::Initialisation(vector<vector<int>> &matrice) {

    sf::RectangleShape cellule(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
    for (int x = 0; x < matrice.size(); ++x) {
        for (int y = 0; y < matrice[0].size(); ++y) {
            if (matrice[x][y] == 1) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::White);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 2) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Green);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 3) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Red);
                jeu.draw(cellule);
            }
        }
    }
    jeu.display();
}

// Afficher la grille à partir de la matrice
void Graphique::AfficherGrille(const vector<vector<int>> &matrice) {

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
            } else if (matrice[x][y] == 2) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Green);
                jeu.draw(cellule);
            } else if (matrice[x][y] == 3) {
                cellule.setPosition(y * taille_cellule, x * taille_cellule);
                cellule.setFillColor(sf::Color::Red);
                jeu.draw(cellule);
            }
        }
    }

    jeu.display();
}

// Mettre à jour une cellule dans la grille
void Graphique::Update(int x, int y, int etat) {
    sf::RectangleShape cellule(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
    cellule.setPosition(y * taille_cellule, x * taille_cellule);
    cellule.setFillColor(etat == 1 ? sf::Color::White : sf::Color::Black);

    jeu.draw(cellule);
}

void Graphique::UpdateGrille(){
    jeu.display();
}


bool Graphique::Events(double *vitesse, bool *changement_cellule, int *x, int *y, int *etat) {
    sf::Event event;
    static auto lastUpdate = chrono::steady_clock::now();
    const auto interval = chrono::milliseconds(150);
    while (jeu.pollEvent(event)) {

        // event fermeture
        if (event.type == sf::Event::Closed) {
            jeu.close();
        } else if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Escape) {
                jeu.close();
            }
        }

        // event vitesse
        auto now = chrono::steady_clock::now();
        if (now - lastUpdate > interval) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
                *vitesse *= 1.1;
                cout << "Vitesse actuelle : " << *vitesse << endl;
                lastUpdate = now;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
                *vitesse *= 0.9;
                cout << "Vitesse actuelle : " << *vitesse << endl;
                lastUpdate = now;
            } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                if (pause == true){
                    *vitesse = temp_vitesse;
                    pause = false;
                    lastUpdate = now;
                } else {
                    temp_vitesse = *vitesse;
                    *vitesse = 999999;
                    pause = true;
                    lastUpdate = now;
                }
            }
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                int col = event.mouseButton.x / taille_cellule;
                int row = event.mouseButton.y / taille_cellule;
                *x = row;
                *y = col;
                *etat = true;
                Update(row, col, 1);
                UpdateGrille();
                return true;
            }
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                int col = event.mouseButton.x / taille_cellule;
                int row = event.mouseButton.y / taille_cellule;
                *x = row;
                *y = col;
                *etat = false;
                Update(row, col, 0);
                UpdateGrille();
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Vérifie si la fenêtre est ouverte ou non
 *
 * @return true si la fenêtre est actuellement ouverte, false si elle est fermé
 */
bool Graphique::FenetreOuverte() const {
    return jeu.isOpen(); // Vérifie si la fenêtre est toujours ouverte
}

// Destructeur
Graphique::~Graphique() {}
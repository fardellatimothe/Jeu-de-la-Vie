#include "Graphique.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <chrono>


/**
 * @brief Constructeur de la classe Graphique.
 *
 * Initialise la fenêtre graphique du jeu de la vie en fonction de la taille de la matrice,
 * en ajustant la taille des cellules et la taille de la fenêtre pour l'affichage.
 * 
 * @param matrice Référence vers la matrice de cellules représentant l'état initial.
 */
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


/**
 * @brief Initialise la grille graphique à partir de la matrice d'état.
 *
 * Cette méthode dessine les cellules de la matrice dans la fenêtre en fonction de leur état :
 * - `1` : cellule vivante (blanche),
 * - `2` : cellule obstacle (verte),
 * - `3` : cellule voisine (rouge).
 *
 * @param matrice Référence vers la matrice d'état des cellules à afficher.
 */
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


/**
 * @brief Affiche la grille à partir de la matrice donnée.
 *
 * Cette méthode redessine la grille complète en nettoyant la fenêtre avant de redessiner chaque cellule 
 * selon son état (blanche pour vivante, verte pour obstacle, rouge pour voisine).
 *
 * @param matrice Référence vers la matrice d'état des cellules à afficher.
 */
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


/**
 * @brief Met à jour l'état d'une cellule spécifique dans la grille graphique.
 *
 * Cette méthode met à jour l'affichage de la cellule dans la fenêtre en fonction de son état 
 * (blanche pour vivante, noire pour morte).
 *
 * @param x Position de la cellule sur l'axe des lignes.
 * @param y Position de la cellule sur l'axe des colonnes.
 * @param etat État de la cellule (1 pour vivante, 0 pour morte).
 */
void Graphique::Update(int x, int y, int etat) {
    sf::RectangleShape cellule(sf::Vector2f(taille_cellule - 1.0f, taille_cellule - 1.0f));
    cellule.setPosition(y * taille_cellule, x * taille_cellule);
    cellule.setFillColor(etat == 1 ? sf::Color::White : sf::Color::Black);

    jeu.draw(cellule);
}


/**
 * @brief Affiche la grille mise à jour après un changement.
 *
 * Cette méthode effectue le rendu final de la fenêtre graphique après une mise à jour de la grille.
 */
void Graphique::UpdateGrille(){
    jeu.display();
}


/**
 * @brief Gère les événements utilisateur tels que les touches et les clics de souris.
 *
 * Cette méthode capte les événements clavier et souris pour ajuster la vitesse d'exécution, 
 * mettre en pause, ou modifier l'état des cellules en fonction des clics gauche et droit.
 * Elle retourne `true` si une cellule a été modifiée.
 *
 * @param vitesse Pointeur vers la vitesse actuelle du jeu.
 * @param changement_cellule Pointeur vers une variable qui indique si l'état d'une cellule a changé.
 * @param x Pointeur vers la position X de la cellule modifiée.
 * @param y Pointeur vers la position Y de la cellule modifiée.
 * @param etat Pointeur vers l'état de la cellule modifiée.
 * @return `true` si une cellule a été modifiée, sinon `false`.
 */
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
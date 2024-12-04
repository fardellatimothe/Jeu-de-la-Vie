#include "GestionFichier.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

GestionFichier::GestionFichier(std::string path) : cheminInitialisation(path) {
    std::ifstream fichier(cheminInitialisation);
    if (fichier.is_open()) {
        fichier >> x_grille >> y_grille;

        matrice_grille = std::vector<std::vector<int>>(x_grille, std::vector<int>(y_grille, 0));
    } else {
        std::cerr << "Le fichier n'a pas été initialisé. " << std::endl;
    }
    fichier.close();
}

GestionFichier::GestionFichier(std::string path, std::string output) : cheminInitialisation(path), cheminSauvegarde(output) {
    std::ifstream fichier(cheminInitialisation);
    if (fichier.is_open()) {
        fichier >> x_grille;
        fichier >> y_grille;

        matrice_grille = std::vector<std::vector<int>>(x_grille, std::vector<int>(y_grille, 0));
    } else {
        std::cerr << "Le fichier n'a pas été initialisé. " << std::endl;
    }
    fichier.close();
}

int GestionFichier::getx() {
    return x_grille;
}

int GestionFichier::gety() {
    return y_grille;
}


void GestionFichier::setMatrice(std::vector<std::vector<int>> *m) {
    matrice_grille = *m;
    return;
}


void GestionFichier::lireEtatInitial() {
    std::ifstream fichier(cheminInitialisation);
    if (fichier.is_open()) {
        fichier.seekg(5, std::ios::beg);
        for (int x = 0; x < getx(); ++x) {
            for (int y = 0; y < gety(); ++y) {
                fichier >> matrice_grille[x][y];
            }
        }
        fichier.close();
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour lire l'état initial." << std::endl;
        return;
    }
}

void GestionFichier::afficherMatrice() const {
    std::cout << x_grille << " " << y_grille << std::endl; // Afficher les dimensions
    for (const auto& ligne : matrice_grille) {
        for (int cell : ligne) {
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
}

void GestionFichier::sauvegarderEtat() {
    if (!(cheminSauvegarde == std::string(""))) {
        std::ofstream fichier(cheminSauvegarde);
        if (fichier.is_open()) {
            for (int x = 0; x < getx(); ++x) {
                for (int y = 0; y < gety(); ++y) {
                    fichier << matrice_grille[x][y];
                    fichier << " ";
                }
                fichier << "\n";
            }
            fichier.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder l'état initial. (1)" << std::endl;
            return;
        }
    } else {
        std::ofstream fichier(cheminInitialisation);
        if (fichier.is_open()) {
            for (int x = 0; x < getx(); ++x) {
                for (int y = 0; y < gety(); ++y) {
                    fichier << matrice_grille[x][y];
                    fichier << " ";
                }
                fichier << "\n";
            }
            fichier.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder l'état initial. (2)" << std::endl;
            return;
        }
    }
    return;
}


void GestionFichier::sauvegarderEtat(std::vector<std::vector<int>> *m) {
    matrice_grille = *m;
    if (!(cheminSauvegarde == std::string(""))) {
        std::ofstream fichier(cheminSauvegarde);
        if (fichier.is_open()) {
            for (int x = 0; x < getx(); ++x) {
                for (int y = 0; y < gety(); ++y) {
                    fichier << matrice_grille[x][y];
                    fichier << " ";
                }
                fichier << "\n";
            }
            fichier.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder l'état initial. (1)" << std::endl;
            return;
        }
    } else {
        std::ofstream fichier(cheminInitialisation);
        if (fichier.is_open()) {
            for (int x = 0; x < getx(); ++x) {
                for (int y = 0; y < gety(); ++y) {
                    fichier << matrice_grille[x][y];
                    fichier << " ";
                }
                fichier << "\n";
            }
            fichier.close();
        } else {
            std::cerr << "Erreur : Impossible d'ouvrir le fichier pour sauvegarder l'état initial. (2)" << std::endl;
            return;
        }
    }
    return;
}

GestionFichier::~GestionFichier() {}
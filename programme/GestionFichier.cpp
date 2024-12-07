#include "GestionFichier.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>

// Constructeur
GestionFichier::GestionFichier() : ite(0) {}


// Constructeur Parametré
GestionFichier::GestionFichier(std::string output) : cheminSauvegarde(output), ite(0) {}


// Lire l'état initial des cellules dans le fichier
std::vector<std::vector<int>>* GestionFichier::lireEtatInitial(std::string cheminInitialisation) {
    std::ifstream fichier(cheminInitialisation);
    if (fichier.is_open()) {
        fichier >> x_grille >> y_grille;
        std::vector<std::vector<int>>* matrice_grille = new std::vector<std::vector<int>>(x_grille, std::vector<int>(y_grille, 0));
        
        for (int x = 0; x < x_grille; ++x) {
            for (int y = 0; y < y_grille; ++y) {
                fichier >> (*matrice_grille)[x][y];
            }
        }

        fichier.close();
        return matrice_grille;
    } else {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier pour lire l'état initial." << std::endl;
        std::vector<std::vector<int>>* matrice_grille = new std::vector<std::vector<int>>(x_grille, std::vector<int>(y_grille, 0));
        return matrice_grille;
    }
}

// Sauvegarder l'etat des cellules dans un fichier
void GestionFichier::sauvegarderEtat(std::vector<std::vector<int>>* matrice_grille) {
    if (!(cheminSauvegarde == std::string(""))) {
        ite++;
        std::string nom_fichier = cheminSauvegarde + "/fichier_ite_" + std::to_string(ite);

        std::ofstream fichier(nom_fichier);
        if (fichier.is_open()) {
            for (int x = 0; x < x_grille; ++x) {
                for (int y = 0; y < y_grille; ++y) {
                    fichier << (*matrice_grille)[x][y];
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
        ite++;
        std::string nom_dossier = "Sauvergarde";
        std::string nom_fichier = nom_dossier + "/fichier_ite_" + std::to_string(ite);

        std::filesystem::create_directory(nom_dossier);

        std::ofstream fichier(nom_fichier);
        if (fichier.is_open()) {
            for (int x = 0; x < x_grille; ++x) {
                for (int y = 0; y < y_grille; ++y) {
                    fichier << (*matrice_grille)[x][y];
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


// Destructeur
GestionFichier::~GestionFichier() {}
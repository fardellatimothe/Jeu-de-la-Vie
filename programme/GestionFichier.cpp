#include "GestionFichier.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <filesystem>


/**
 * @brief Constructeur par défaut de la classe GestionFichier.
 *
 * Initialise une instance de GestionFichier avec un compteur d'itérations 
 * (ite) à 0 et sans chemin de sauvegarde défini.
 */
GestionFichier::GestionFichier() : ite(0) {}


/**
 * @brief Constructeur paramétré de la classe GestionFichier.
 *
 * Initialise une instance de GestionFichier avec un chemin de sauvegarde spécifié 
 * et un compteur d'itérations (ite) à 0.
 *
 * @param output Chemin où les fichiers de sauvegarde seront enregistrés.
 */
GestionFichier::GestionFichier(std::string output) : chemin_sauvegarde(output), ite(0) {}


/**
 * @brief Lit l'état initial des cellules à partir d'un fichier.
 *
 * Cette méthode charge une matrice d'état initial à partir du fichier spécifié.
 * Si le fichier ne peut pas être ouvert, une matrice vide est retournée, et une 
 * erreur est affichée.
 *
 * @param cheminInitialisation Chemin vers le fichier contenant l'état initial.
 * @return Pointeur vers une matrice d'entiers représentant l'état initial des cellules.
 */
std::vector<std::vector<int>>* GestionFichier::LireEtatInitial(std::string cheminInitialisation) {
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


/**
 * @brief Sauvegarde l'état actuel des cellules dans un fichier.
 *
 * Enregistre la matrice actuelle dans un fichier au chemin spécifié. Si aucun chemin 
 * n'est défini, un dossier par défaut nommé "Sauvegarde" est créé pour y stocker les fichiers.
 *
 * @param matrice_grille Pointeur vers une matrice contenant l'état actuel des cellules.
 */
void GestionFichier::SauvegarderEtat(std::vector<std::vector<int>>* matrice_grille) {
    if (!(chemin_sauvegarde == std::string(""))) {
        ite++;
        std::string nom_fichier = chemin_sauvegarde + "/fichier_ite_" + std::to_string(ite);

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


/**
 * @brief Destructeur de la classe GestionFichier.
 *
 * Libère les ressources associées à l'instance de GestionFichier si nécessaire.
 */
GestionFichier::~GestionFichier() {}
#include <iostream>
#include <fstream>
#include <filesystem>
#include <bits/fs_ops.h>

int main() {
    std::string dir = "mon_dossier";
    std::string fichier = dir + "/mon_fichier.txt";  // Créer un fichier dans le dossier

    // Créer le répertoire si nécessaire
    if (!std::filesystem::exists(dir)) {
        if (std::filesystem::create_directory(dir)) {
            std::cout << "Le dossier a été créé avec succès." << std::endl;
        } else {
            std::cerr << "Erreur lors de la création du dossier." << std::endl;
            return 1;
        }
    }

    // Créer un fichier dans ce répertoire
    std::ofstream fichier_out(fichier);
    if (fichier_out.is_open()) {
        fichier_out << "Hello, World!" << std::endl;
        fichier_out.close();
        std::cout << "Fichier créé avec succès." << std::endl;
    } else {
        std::cerr << "Erreur lors de la création du fichier." << std::endl;
    }

    return 0;
}

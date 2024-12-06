#include <iostream>
#include "Controleur.h"
using namespace std;

#include <iostream>
#include <string>
#include <chrono>
using namespace std;

int main(int argc, char* argv[]) {
    Controleur jeu_de_la_vie;

    if (argc < 2) {
        cerr << "Usage : " << argv[0] << " [mode] [paramètres...]\n";
        cerr << "Mode Console : " << argv[0] << " console fichier_input.txt iteration_max\n";
        cerr << "Mode Graphique : " << argv[0] << " graphique fichier_input.txt fichier_output.txt vitesse\n";
        return 1;
    }

    string mode = argv[1];

    if (mode == "console") {
        if (argc < 6) {
            cerr << "Paramètres insuffisants pour le mode Console.\n";
            return 1;
        }
        string fichier_input = argv[2];
        string fichier_output = argv[3];
        int iteration_max = stod(argv[4]);
        
        string str_grilleTorique = argv[5];
        bool grilleTorique;
        if (str_grilleTorique == "true") {
            grilleTorique = true;
        } else {
            grilleTorique = false;
        }

        cout << "Test : " << grilleTorique << endl; // Active l'affichage "true"/"false"

        jeu_de_la_vie.start(fichier_input, fichier_output, iteration_max, grilleTorique);

    } else if (mode == "graphique") {
        if (argc < 5) {
            cerr << "Paramètres insuffisants pour le mode Graphique.\n";
            return 1;
        }
        string fichier_input = argv[2];
        double vitesse = stod(argv[3]);
        string str_grilleTorique = argv[4];
        bool grilleTorique;
        if (str_grilleTorique == "true") {
            grilleTorique = true;
        } else if (str_grilleTorique == "false"){
            grilleTorique = false;
        } else {
            cerr << "Erreur mode grille torique: Utilisez 'true' ou 'false' pour le mode grille torique.\n";
            return 1;
        }
        cout << "Test : " << grilleTorique << endl; // Active l'affichage "true"/"false"

        jeu_de_la_vie.start(fichier_input, vitesse, grilleTorique);
    } else {
        cerr << "Mode inconnu. Utilisez 'console' ou 'graphique'.\n";
        return 1;
    }

    return 0;
}



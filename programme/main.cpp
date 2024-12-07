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
        cerr << "Mode Console : " << argv[0] << " console fichier_input.txt dossier_output iteration_max\n";
        cerr << "Mode Graphique : " << argv[0] << " graphique fichier_input.txt vitesse\n";
        cerr << "Mode de Test : " <<  argv[0] << " test fichier_base.txt fichier_attendu.txt iteration_test\n";
        cerr << "Mode Graphique & Console : " << argv[0] << " gc fichier_input.txt dossier_ouput interation_max vitesse\n";
        return 1;
    }

    string mode = argv[1];

    if (mode == "console") {
        if (argc < 5) {
            cerr << "Paramètres insuffisants pour le mode Console.\n";
            return 1;
        }
        string fichier_input = argv[2];
        string fichier_output = argv[3];
        int iteration_max = stod(argv[4]);
        if(!jeu_de_la_vie.test("Test/test_unitaire1.txt", "Test/test_unitaire2.txt", 5)) return 0; // test unitaire
        jeu_de_la_vie.start(fichier_input, fichier_output, iteration_max);

    } else if (mode == "graphique") {
        if (argc < 4) {
            cerr << "Paramètres insuffisants pour le mode Graphique.\n";
            return 1;
        }
        string fichier_input = argv[2];
        double vitesse = stod(argv[3]);
        if(!jeu_de_la_vie.test("Test/test_unitaire1.txt", "Test/test_unitaire2.txt", 5)) return 0; // test unitaire
        jeu_de_la_vie.start(fichier_input, vitesse);
    } else if (mode == "gc") {
        if (argc < 6) {
            cerr << "Paramètres insuffisants pour lancer les deux modes.\n";
            return 1;
        }
        string fichier_input = argv[2];
        string fichier_output = argv[3];
        int iteration_max = stoi(argv[4]);
        double vitesse = stod(argv[5]);
        if(!jeu_de_la_vie.test("Test/test_unitaire1.txt", "Test/test_unitaire2.txt", 5)) return 0; // test unitaire
        jeu_de_la_vie.start(fichier_input, fichier_output, iteration_max, vitesse);

    } else if (mode == "test") {
        if (argc < 4) {
            cerr << "Paramètre insuffisants pour réaliser un test unitaire";
            return 1;
        }
        string fichier_base = argv[2];
        string fichier_attendu = argv[3];
        int iteration_test = stod(argv[4]);
        jeu_de_la_vie.test(fichier_base,fichier_attendu,iteration_test);
    } else {
        cerr << "Mode inconnu. Utilisez 'console' ou 'graphique'.\n";
        return 1;
    }

    return 0;
}


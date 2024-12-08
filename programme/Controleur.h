#ifndef CONTROLEUR_H
#define CONTROLEUR_H 

#include <iostream>
#include <vector>
#include <string>
#include <chrono>

#include "Console.h"
#include "Grille.h"
#include "Observable.h"
#include "GestionFichier.h"
#include "Graphique.h"

using namespace std;

class Controleur {
private:
    int iteration=0;
public:
    Controleur(){}
    ~Controleur(){}

    void start(string chemin_initial, string chemin_sauvegarde, int iteration_max, bool grilleTorique); // mode console
    void start(string chemin_initial, double& vitesse, bool grilleTorique); // Mode Graphique
    void start(string chemin_initial, string chemin_sauvegarde, int iteration_max, double &vitesse, bool grilleTorique); // 2 modes
    bool test(string fichier_base, string fichier_attendu, int iteration_test); // Mode de test unitaire
};

#endif

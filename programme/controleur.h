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

public:
    Controleur(){}
    ~Controleur(){}
    void start(int iteration_max, string chemin_initial, string chemin_sauvegarde); // mode console
    void start(string chemin_initial, double vitesse);
};

#endif

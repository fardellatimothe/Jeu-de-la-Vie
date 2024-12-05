#ifndef CONTROLEUR_H
#define CONTROLEUR_H 

#include <iostream>
#include <vector>
#include <string>

#include "Console.h"
#include "Grille.h"
#include "Observable.h"
#include "GestionFichier.h"
using namespace std;

class Controleur {

public:
    Controleur(){}
    ~Controleur(){}
    void start(int iteration_max, string chemin_initial, string chemin_sauvegarde); // mode console
};

#endif

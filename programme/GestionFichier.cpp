#include "GestionFichier.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

GestionFichier::GestionFichier(std::string path) : cheminInitialisation(path) {}

GestionFichier::GestionFichier(std::string path, std::string output) : cheminInitialisation(path), cheminSauvegarde(output) {}


void lireEtatInitial() {
    ;
}

void sauvegarderEtat() {
    ;
}

GestionFichier::~GestionFichier() {}
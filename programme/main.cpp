#include "Grille.h"
#include <iostream>
#include <vector>
#include "Console.h"
#include "Observable.h"
#include "GestionFichier.h"
#include <chrono>
using namespace std;

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    GestionFichier gestionFichier("fichier_input.txt","Test");
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Console console = Console(test);
    Grille grille = Grille(*test);
    grille.ajouterObservateurs(&console);
    //console.afficherMatrice();

    for (int i=0; i<50; i++){
        grille.calculerProchaineIteration();
        gestionFichier.sauvegarderEtat(test);
    }

    //console.afficherMatrice();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Temps d'exécution : " << duration.count() << " secondes" << std::endl;

    return 0;
}


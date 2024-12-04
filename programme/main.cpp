#include "Grille.h"
#include <iostream>
#include <vector>
#include "Console.h"
#include "Observable.h"
#include "GestionFichier.h"

using namespace std;

int main(){
    GestionFichier gestionFichier("fichier_input.txt","Test");
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Console console = Console(test);
    Grille grille = Grille(*test);
    grille.ajouterObservateurs(&console);
    console.afficherMatrice();

    for (int i=0; i<20; i++){
        grille.calculerProchaineIteration();
        gestionFichier.sauvegarderEtat(test);
    }

    console.afficherMatrice();
    

    return 0;
}


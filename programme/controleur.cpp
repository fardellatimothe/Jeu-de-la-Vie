#include "controleur.h"

void Controleur::start(int iteration_max, string chemin_initial, string chemin_sauvegarde){    
    GestionFichier gestionFichier(chemin_initial, chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Console console(test);
    Grille grille(*test);

    grille.ajouterObservateurs(&console);
    console.afficherMatrice();

    for (int i=0; i<iteration_max; i++){
        grille.calculerProchaineIteration();
        gestionFichier.sauvegarderEtat(test);
        if (grille.estStable()) return;
    }
}
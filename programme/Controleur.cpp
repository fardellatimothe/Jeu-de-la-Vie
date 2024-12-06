#include "Controleur.h"

void Controleur::start(string chemin_initial, string chemin_sauvegarde, int iteration_max, bool grilleTorique){    
    GestionFichier gestionFichier(chemin_initial, chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Console console(test);
    Grille grille(*test, grilleTorique);

    grille.ajouterObservateurs(&console);
    console.afficherMatrice();

    for (int i=0; i<iteration_max; i++){
        grille.calculerProchaineIteration();
        gestionFichier.sauvegarderEtat(test);
        if (grille.estStable()) return;
    }
}

void Controleur::start(string chemin_initial, double vitesse, bool grilleTorique){
    auto test1 = chrono::high_resolution_clock::now();
    GestionFichier gestionFichier(chemin_initial, "");
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Graphique graphique = Graphique(*test);
    Grille grille(*test, grilleTorique);

    grille.ajouterObservateurs(&graphique);
    
    graphique.initialiser(*test);
    
    cout << grille.TaillePile() << endl;

    while (graphique.fenetreOuverte()){
        grille.calculerProchaineIteration();
        iteration++;
        graphique.update_grille();

        auto start = chrono::high_resolution_clock::now();
        while ((chrono::high_resolution_clock::now() - start) < chrono::duration<double>(vitesse))
        {
            graphique.handleEvents();
        }
        
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - test1;
    cout << "Itération : " << iteration << " en " << duration.count() << " secondes" << endl;
}
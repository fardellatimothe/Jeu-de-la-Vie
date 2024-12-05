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

void Controleur::start(string chemin_initial, double vitesse){
    // auto test1 = chrono::high_resolution_clock::now();
    GestionFichier gestionFichier(chemin_initial, "");
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Graphique graphique = Graphique(*test);
    Grille grille(*test);

    cout << "Nombre cellules vivantes : " << grille.TaillePile() << endl;

    grille.ajouterObservateurs(&graphique);
    
    graphique.initialiser(*test);


    while (graphique.fenetreOuverte()){
        grille.calculerProchaineIteration();
        // auto end1 = chrono::high_resolution_clock::now();
        // chrono::duration<double> duration = end1 - test1;
        // cout << "Temps d'exécution : " << duration.count() << " secondes" << endl;

        auto start = chrono::high_resolution_clock::now();
        while ((chrono::high_resolution_clock::now() - start) < chrono::duration<double>(vitesse))
        {
            graphique.handleEvents();
        }
        
    }
}
#include "Controleur.h"

void Controleur::start(string chemin_initial, string chemin_sauvegarde, int iteration_max, bool grilleTorique){    
    GestionFichier gestionFichier(chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial(chemin_initial);

    Console console(test);
    Grille grille(*test, grilleTorique);

    grille.ajouterObservateurs(&console);
    // console.afficherMatrice();

    for (int i=0; i<iteration_max; i++){
        grille.calculerProchaineIteration();
        gestionFichier.sauvegarderEtat(test);
        if (grille.estStable()) return;
    }
}

bool Controleur::test(string fichier_base, string fichier_attendu, int iteration_test) {
    GestionFichier gestionFichier = GestionFichier();
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial(fichier_base);

    Console console(test);
    Grille grille(*test, false);

    grille.ajouterObservateurs(&console);
    // console.afficherMatrice();

    for (int i=0; i<iteration_test; i++){
        grille.calculerProchaineIteration();
    }

    vector<std::vector<int>>* testu = gestionFichier.lireEtatInitial(fichier_attendu);
    
    for (size_t i = 0; i < test->size(); ++i) {
        for (size_t j = 0; j < (*test)[0].size(); ++j) {
            if ((*test)[i][j] != (*testu)[i][j]) {
                cout << "Le test n'est pas validé" << endl;
                return 0;
            }
        }
    }

    cout << "Le test est validé !" << endl;
    return 1;
}
void Controleur::start(string chemin_initial, double &vitesse, bool grilleTorique){
    auto test1 = chrono::high_resolution_clock::now();
    GestionFichier gestionFichier("");
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial(chemin_initial);

    Graphique graphique = Graphique(*test);
    Grille grille(*test, grilleTorique);

    grille.ajouterObservateurs(&graphique);
    
    graphique.initialiser(*test);
    
    cout << grille.TaillePile() << endl;

    while (graphique.fenetreOuverte() && !(grille.estStable())){
        grille.calculerProchaineIteration();
        iteration++;
        graphique.update_grille();
        auto start = chrono::high_resolution_clock::now();
        while ((chrono::high_resolution_clock::now() - start) < chrono::duration<double>(vitesse))
        {
            graphique.Events(&vitesse);
            if (!graphique.fenetreOuverte()) return;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - test1;
    cout << "Itération : " << iteration << " en " << duration.count() << " secondes" << endl;
}

void Controleur::start(string chemin_initial, string chemin_sauvegarde, int iteration_max, double &vitesse, bool grilleTorique) {
    auto test1 = chrono::high_resolution_clock::now();
    GestionFichier gestionFichier(chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial(chemin_initial);

    Console console(test);
    Graphique graphique = Graphique(*test);
    Grille grille(*test, grilleTorique);

    grille.ajouterObservateurs(&graphique);
    grille.ajouterObservateurs(&console);

    graphique.initialiser(*test);

    while (graphique.fenetreOuverte() && !(grille.estStable()) && (Controleur::iteration < iteration_max)) {
        grille.calculerProchaineIteration();
        iteration++;
        gestionFichier.sauvegarderEtat(test);
        graphique.update_grille();

        auto start = chrono::high_resolution_clock::now();
        while ((chrono::high_resolution_clock::now() - start) < chrono::duration<double>(vitesse)) {
            graphique.Events(&vitesse);
            if (!graphique.fenetreOuverte()) return;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - test1;
    cout << "Itération : " << iteration << " en " << duration.count() << " secondes" << endl;
}
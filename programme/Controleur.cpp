#include "Controleur.h"

void Controleur::start(string chemin_initial, string chemin_sauvegarde, int iteration_max, bool grilleTorique){    
    GestionFichier gestionFichier(chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.LireEtatInitial(chemin_initial);

    Console console(test);
    Grille grille(*test, grilleTorique);

    grille.AjtObservateurs(&console);
    // console.afficherMatrice();

    for (int i=0; i<iteration_max; i++){
        grille.CalculerProchaineIteration();
        gestionFichier.SauvegarderEtat(test);
        if (grille.EstStable()) return;
    }
}

bool Controleur::test(string fichier_base, string fichier_attendu, int iteration_test) {
    GestionFichier gestionFichier = GestionFichier();
    vector<std::vector<int>>* test = gestionFichier.LireEtatInitial(fichier_base);

    Console console(test);
    Grille grille(*test, false);

    grille.AjtObservateurs(&console);
    // console.afficherMatrice();

    for (int i=0; i<iteration_test; i++){
        grille.CalculerProchaineIteration();
    }

    vector<std::vector<int>>* testu = gestionFichier.LireEtatInitial(fichier_attendu);
    
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
    
    // Changement de cellule par click
    bool changement_cellule = false;
    int x;
    int y;
    int etat;

    GestionFichier gestionFichier("");
    vector<std::vector<int>>* test = gestionFichier.LireEtatInitial(chemin_initial);

    Graphique graphique = Graphique(*test);
    Grille grille(*test, grilleTorique);

    grille.AjtObservateurs(&graphique);
    
    graphique.Initialisation(*test);
    
    cout << grille.TaillePile() << endl;

    while (graphique.FenetreOuverte()){
        grille.CalculerProchaineIteration();
        iteration++;
        graphique.UpdateGrille();
        auto start = chrono::high_resolution_clock::now();
        while ((chrono::high_resolution_clock::now() - start) < chrono::duration<double>(vitesse))
        {
            if (graphique.Events(&vitesse, &changement_cellule, &x, &y, &etat)){
                grille.ModifCellule(x, y, etat);
            }
            if (!graphique.FenetreOuverte()) return;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - test1;
    cout << "Itération : " << iteration << " en " << duration.count() << " secondes" << endl;
}

void Controleur::start(string chemin_initial, string chemin_sauvegarde, int iteration_max, double &vitesse, bool grilleTorique) {
    auto test1 = chrono::high_resolution_clock::now();

    // Changement de cellule par click
    bool changement_cellule = false;
    int x;
    int y;
    int etat;

    GestionFichier gestionFichier(chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.LireEtatInitial(chemin_initial);

    Console console(test);
    Graphique graphique = Graphique(*test);
    Grille grille(*test, grilleTorique);

    grille.AjtObservateurs(&graphique);
    grille.AjtObservateurs(&console);

    graphique.Initialisation(*test);

    while (graphique.FenetreOuverte() && !(grille.EstStable()) && (Controleur::iteration < iteration_max)) {
        grille.CalculerProchaineIteration();
        iteration++;
        gestionFichier.SauvegarderEtat(test);
        graphique.UpdateGrille();

        auto start = chrono::high_resolution_clock::now();
        while ((chrono::high_resolution_clock::now() - start) < chrono::duration<double>(vitesse)) {
            if (graphique.Events(&vitesse, &changement_cellule, &x, &y, &etat)){
                grille.ModifCellule(x, y, etat);
            }
            if (!graphique.FenetreOuverte()) return;
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - test1;
    cout << "Itération : " << iteration << " en " << duration.count() << " secondes" << endl;
}
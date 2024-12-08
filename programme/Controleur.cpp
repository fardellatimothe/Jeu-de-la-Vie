#include "Controleur.h"


/**
 * @brief Lance une simulation du jeu de la vie en mode console.
 *
 * Cette méthode initialise une grille à partir d'un fichier d'état initial et simule 
 * le jeu de la vie pour un nombre maximum d'itérations ou jusqu'à stabilisation.
 * Les états successifs sont sauvegardés dans un fichier.
 *
 * @param chemin_initial Chemin vers le fichier contenant l'état initial de la grille.
 * @param chemin_sauvegarde Chemin vers le fichier où les états successifs seront sauvegardés.
 * @param iteration_max Nombre maximal d'itérations à effectuer.
 * @param grilleTorique Indique si la grille est torique (true) ou non (false).
 */
void Controleur::start(string chemin_initial, string chemin_sauvegarde, int iteration_max, bool grilleTorique){    

    GestionFichier gestionFichier(chemin_sauvegarde);
    vector<std::vector<int>>* test = gestionFichier.LireEtatInitial(chemin_initial);

    Console console(test);
    Grille grille(*test, grilleTorique);

    grille.AjtObservateurs(&console);

    // Simulation
    for (int i=0; i<iteration_max; i++){
        grille.CalculerProchaineIteration();
        gestionFichier.SauvegarderEtat(test);
        if (grille.EstStable()) return;
    }
}


/**
 * @brief Lance une simulation interactive avec affichage graphique.
 *
 * Cette méthode initialise une grille à partir d'un fichier d'état initial et simule 
 * le jeu de la vie avec un contrôle interactif de la vitesse et la possibilité de modifier 
 * les cellules en temps réel par clic.
 *
 * @param chemin_initial Chemin vers le fichier contenant l'état initial de la grille.
 * @param vitesse Référence vers une variable contrôlant la vitesse de la simulation (en secondes).
 * @param grilleTorique Indique si la grille est torique (true) ou non (false).
 */
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

    // Simulation
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


/**
 * @brief Lance une simulation combinant mode console et affichage graphique.
 *
 * Cette méthode initialise une grille à partir d'un fichier d'état initial et simule 
 * le jeu de la vie en affichant les états dans la console et graphiquement. Les états 
 * sont sauvegardés et la simulation s'arrête selon plusieurs critères : fermeture de la fenêtre, 
 * stabilisation de la grille, ou dépassement du nombre maximal d'itérations.
 *
 * @param chemin_initial Chemin vers le fichier contenant l'état initial de la grille.
 * @param chemin_sauvegarde Chemin vers le fichier où les états successifs seront sauvegardés.
 * @param iteration_max Nombre maximal d'itérations à effectuer.
 * @param vitesse Référence vers une variable contrôlant la vitesse de la simulation (en secondes).
 * @param grilleTorique Indique si la grille est torique (true) ou non (false).
 */
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

    // Simulation
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


/**
 * @brief Teste la validité des itérations du jeu de la vie.
 *
 * Cette méthode compare l'état d'une grille obtenue après un nombre donné d'itérations 
 * avec un état attendu fourni dans un fichier. Si les états correspondent, le test est validé.
 *
 * @param fichier_base Chemin vers le fichier contenant l'état initial de la grille.
 * @param fichier_attendu Chemin vers le fichier contenant l'état attendu après les itérations.
 * @param iteration_test Nombre d'itérations à effectuer sur la grille.
 * @return True si l'état obtenu correspond à l'état attendu, False sinon.
 */
bool Controleur::test(string fichier_base, string fichier_attendu, int iteration_test) {

    GestionFichier gestionFichier = GestionFichier();
    vector<std::vector<int>>* test = gestionFichier.LireEtatInitial(fichier_base);

    Console console(test);
    Grille grille(*test, false);

    grille.AjtObservateurs(&console);

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
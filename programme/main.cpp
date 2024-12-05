#include "Grille.h"
#include <iostream>
#include <vector>
#include "Console.h"
#include "Observable.h"
#include "GestionFichier.h"
#include "Graphique.h"

using namespace std;

int main(){
    GestionFichier gestionFichier("fichier_input.txt","Test");
    vector<std::vector<int>>* test = gestionFichier.lireEtatInitial();

    Graphique inte = Graphique(*test);
    Grille grille = Grille(*test);

    inte.initialiser(*test);

    // Boucle principale
    while (inte.fenetreOuverte()) {
        inte.handleEvents(); // Gérer les événements utilisateur

        // Simulation simple (mettez à jour votre matrice ici si nécessaire)
        inte.update(2,0,1);
    }
    
    // grille.ajouterObservateurs(&console);
    // console.afficherMatrice();
    // grille.calculerProchaineIteration();
    // console.afficherMatrice();

    return 0;
}


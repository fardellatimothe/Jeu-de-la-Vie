#include <iostream>
#include "controleur.h"
using namespace std;

int main(){
    auto start = chrono::high_resolution_clock::now();
    Controleur jeu_de_la_vie = Controleur();

    //jeu_de_la_vie.start(1, "fichier_input.txt", "Test");
    jeu_de_la_vie.start("fichier_input.txt", 0.00001);
    
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;
    //cout << "Temps d'exécution : " << duration.count() << " secondes" << endl;

    return 0;
}


#include <iostream>
#include <chrono>
#include "controleur.h"
using namespace std;

int main(){
    auto start = std::chrono::high_resolution_clock::now();
    Controleur jeu_de_la_vie = Controleur();

    jeu_de_la_vie.start(5, "fichier_input.txt", "Test");
    
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Temps d'exécution : " << duration.count() << " secondes" << std::endl;

    return 0;
}


#include "Grille.h"
#include <iostream>
#include <vector>
#include "Console.h"
#include "Observable.h"

using namespace std;

int main(){
    std::vector<std::vector<int>> grid(50, std::vector<int>(50));
 
    for (int x = 0; x < 20; ++x) {
        for (int y = 0; y < 20; ++y) {
            if ((x+y)%2){
                grid[x][y] = 1;
            } else {
                grid[x][y] = 0;
            }
        }
    }

    Console console = Console(&grid);
    Grille grille = Grille(grid);
    grille.ajouterObservateurs(&console);
    console.afficherMatrice();
    grille.calculerProchaineIteration();
    cout << "Nombre cellules vivante: " << grille.TaillePile() << endl;
    console.afficherMatrice();
    
}
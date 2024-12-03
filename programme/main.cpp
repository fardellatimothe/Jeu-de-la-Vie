#include "Grille.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Grille grille;

    std::vector<std::vector<int>> grid(3, std::vector<int>(3));
 
    // for (int x = 0; x < 20; ++x) {
    //     for (int y = 0; y < 20; ++y) {
    //         if ((x+y)%2){
    //             grid[x][y] = 1;
    //         } else {
    //             grid[x][y] = 0;
    //         }
    //     }
    // }
    grid[2][0] = 1;
    grid[0][0] = 1;
    grille.initialiser(grid);
    grille.calculerProchaineIteration();
    cout << "Nombre d'entité : " << grille.TaillePile() << endl;
    cout << "Voisin : " << grille.nbVoisin(1, 0) << endl;
}
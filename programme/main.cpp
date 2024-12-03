#include "Grille.h"
#include <iostream>
#include <vector>
#include "Console.h"
#include "Observable.h"

using namespace std;

int main(){
    Observer* console = new Console;
    Observable observable;

    observable.ajouterObservateurs(console);

    std::vector<std::vector<int>> grid(5, std::vector<int>(5));
 
    // for (int x = 0; x < 20; ++x) {
    //     for (int y = 0; y < 20; ++y) {
    //         if ((x+y)%2){
    //             grid[x][y] = 1;
    //         } else {
    //             grid[x][y] = 0;
    //         }
    //     }
    // }
    //grid[2][0] = 1;
    grid[0][0] = 1;
    grid[1][0] = 1;
    grid[0][1] = 1;
    grid[2][0] = 1;
    Grille grille(grid);
    grille.calculerProchaineIteration();
    cout << "Nombre cellules vivante: " << grille.TaillePile() << endl;
}
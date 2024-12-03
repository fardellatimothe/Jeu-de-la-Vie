#include "Grille.h"
#include <iostream>
#include <vector>

using namespace std;

int main(){
    Grille grille;

    std::vector<std::vector<int>> grid(50, std::vector<int>(50));
 
    for (int x = 0; x < 50; ++x) {
        for (int y = 0; y < 50; ++y) {
            grid[x][y] = 0;
        }
    }
    grid[0][0] = 1;
    grille.initialiser(grid);
    cout << "Nombre d'entité : " << grille.TaillePile() << endl;
}
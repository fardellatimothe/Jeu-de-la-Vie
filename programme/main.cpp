#include "Grille.h"
#include <iostream>
#include <vector>

using namespace std;

const int cellSize = 10;
const int gridWidth = 80;
const int gridHeight = 80;
std::vector<std::vector<int>> grid(gridWidth, std::vector<int>(gridHeight));

void initializeGrid() {
    for (int x = 0; x < gridWidth; ++x) {
        for (int y = 0; y < gridHeight; ++y) {
            grid[x][y] = std::rand() % 2;
        }
    }
}   

int main(){
    Grille grille;
    grille.initialiser(grid);
}
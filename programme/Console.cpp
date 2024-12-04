#include "Console.h"

void Console::update(int x, int y, int etat){
    Matrice->at(x).at(y) = etat;
}

Console::Console(vector<vector<int>>* grid) : Matrice(grid) {}

void Console::afficherMatrice() const {
        for (const auto& ligne : *Matrice) {
            for (int val : ligne) {
                std::cout << val << " ";
            }
            std::cout << "\n";
        }
    }
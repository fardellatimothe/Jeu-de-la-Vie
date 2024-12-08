#include "Console.h"

void Console::Update(int x, int y, int etat){
    matrice->at(x).at(y) = etat;
}

Console::Console(vector<vector<int>>* grid) : matrice(grid) {}

void Console::AfficherMatrice() const {
    for (const auto& ligne : *matrice) {
        for (int val : ligne) {
            cout << val << " ";
        }
        cout << "\n";
    }
}
#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <stack>
#include <iostream>
#include "CelluleVivante.h"
#include "CelluleVoisine.h"
using namespace std;

class Grille {
private:
    stack<Cellule*> CelluleVivantePile;
    stack<Cellule*> CelluleTransition;
    vector<vector<Cellule*>> CelluleExiste;
    int nbVoisin(int x, int y);

public:
    Grille(vector<vector<int>>& matrice);
    void calculerProchaineIteration();
    void CalculVoisin();
    void CalculSurvie();
    int TaillePile();
    bool estStable() const;

};

#endif

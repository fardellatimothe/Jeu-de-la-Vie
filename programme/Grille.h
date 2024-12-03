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

public:
    void initialiser(vector<vector<int>>& matrice);
    void calculerProchaineIteration();
    int TaillePile();
    int nbVoisin(int x, int y);
    bool estStable() const;

};

#endif

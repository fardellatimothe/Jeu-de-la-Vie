#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <stack>
#include "CelluleVivante.h"
#include "CelluleVoisine.h"

class Grille {
private:
    std::stack<Cellule*> CelluleVivantePile;
    std::stack<Cellule*> CelluleTransition;

public:
    void initialiser(std::vector<std::vector<int>>& matrice);
    void calculerProchaineIteration();
    bool estStable() const;

};

#endif

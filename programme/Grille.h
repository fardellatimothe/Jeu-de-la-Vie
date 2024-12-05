#ifndef GRILLE_H
#define GRILLE_H

#include <stack>
#include <iostream>
#include "Observers.h"
#include "Observable.h"
#include "CelluleVivante.h"
#include "CelluleVoisine.h"

class Grille : public Observable{
private:
    stack<Cellule*> CelluleVivantePile;
    stack<Cellule*> CelluleTransition;
    vector<vector<Cellule*>> CelluleExiste;
    int nbVoisin(int x, int y);
    bool stable;

public:
    Grille(vector<vector<int>>& matrice);
    void calculerProchaineIteration();
    void CalculVoisin();
    void CalculSurvie();
    int TaillePile();
    bool estStable() const;
    virtual void notifierObservateur(int x, int y, int etat) override;
};

#endif

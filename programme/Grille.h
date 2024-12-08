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
    stack<Cellule*> cell_vivante_pile;
    stack<Cellule*> temp_pile;
    vector<vector<Cellule*>> existe_pile;
    int nb_voisin(int x, int y);
    bool stable=false;
    bool grille_torique=false;

public:
    Grille(vector<vector<int>>& matrice, bool grille_torique);
    void CalculerProchaineIteration();
    void CalculVoisin();
    void CalculSurvie();
    void ModifCellule(int x, int y, int etat);
    int TaillePile();
    bool EstStable() const;
    virtual void NotifObservateur(int x, int y, int etat) override;
};

#endif

#ifndef CELLULE_H
#define CELLULE_H

#include <vector>
using namespace std;

class Cellule {
public:
    Cellule(int x, int y);
    virtual ~Cellule() {}
    virtual bool CalculerProchainEtat() = 0;
    void IncrementerVoisinesVivantes();
    int GetX() const;
    int GetY() const;
    int GetVoisin() const;
    void ResetVoisin();
    virtual int Etat() const = 0;

protected:
    int nb_voisines_vivantes=0;
    int x, y;    
};

#endif

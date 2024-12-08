#ifndef CELLULE_H
#define CELLULE_H

#include <vector>
using namespace std;

class Cellule {
protected:
    bool doit_mourir = false;

public:
    Cellule(int x, int y);
    virtual ~Cellule() {}
    virtual bool CalculerProchainEtat() = 0;
    void IncrementerVoisinesVivantes();
    int GetX() const;
    int GetY() const;
    bool GetDoitMourir() const;
    int GetVoisin() const;
    void ResetVoisin();
    virtual int Etat() const = 0;
    void DoitMourir();
    

protected:
    int nb_voisines_vivantes=0;
    int x, y;    
};

#endif

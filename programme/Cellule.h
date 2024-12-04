#ifndef CELLULE_H
#define CELLULE_H

#include <vector>
using namespace std;

class Cellule {

protected:
    int nbVoisinesVivantes;
    int x, y;    

public:
    Cellule(int x, int y);
    virtual ~Cellule() {}
    virtual bool calculerProchainEtat() = 0;
    void IncrementerVoisinesVivantes();
    int getx() const;
    int gety() const;
    int getVoisin() const;
    void resetVoisin();
    virtual int etat() const = 0;
};

#endif

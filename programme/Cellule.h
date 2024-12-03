#ifndef CELLULE_H
#define CELLULE_H

#include "Observers.h"
#include "Observable.h"
#include <vector>
using namespace std;

class Cellule : public Observable {

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
};

#endif

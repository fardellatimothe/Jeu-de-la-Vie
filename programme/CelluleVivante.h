#ifndef CELLULEVIVANTE_H
#define CELLULEVIVANTE_H

#include "Cellule.h"

class CelluleVivante : public Cellule {
private:
    bool obstacle;
public:
    CelluleVivante(int x, int y, bool obstacle);
    CelluleVivante(int x, int y);

    virtual ~CelluleVivante() override{}
    virtual bool calculerProchainEtat() override;
    virtual int etat() const override;
};

#endif

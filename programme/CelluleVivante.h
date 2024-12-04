#ifndef CELLULEVIVANTE_H
#define CELLULEVIVANTE_H

#include "Cellule.h"

class CelluleVivante : public Cellule {
public:
    CelluleVivante(int x, int y);
    virtual ~CelluleVivante() override{}
    virtual bool calculerProchainEtat() override;
    virtual int etat() const override;
};

#endif

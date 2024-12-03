#ifndef CELLULEVIVANTE_H
#define CELLULEVIVANTE_H

#include "Cellule.h"

class CelluleVivante : public Cellule {
public:
    CelluleVivante(int x, int y);
    bool estVivante() const;
    virtual void calculerProchainEtat() override;
};

#endif

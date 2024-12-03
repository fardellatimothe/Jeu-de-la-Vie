#ifndef CELLULEVOISINE_H
#define CELLULEVOISINE_H

#include "Cellule.h"

class CelluleVoisine : public Cellule {
public:
    CelluleVoisine(int x, int y);
    bool estVivante() const;
    virtual void calculerProchainEtat() override;
};

#endif // CELLULEVOISINE_H

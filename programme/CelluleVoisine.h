#ifndef CELLULEVOISINE_H
#define CELLULEVOISINE_H

#include "Cellule.h"

class CelluleVoisine : public Cellule {
public:
    CelluleVoisine(int x, int y);
    bool estVivante() const;
    void calculerProchainEtat() override;
};

#endif // CELLULEVOISINE_H

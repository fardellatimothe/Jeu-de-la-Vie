#ifndef CELLULEVOISINE_H
#define CELLULEVOISINE_H

#include "Cellule.h"

class CelluleVoisine : public Cellule {
public:
    CelluleVoisine(int x, int y);
    virtual ~CelluleVoisine() override{}
    virtual bool calculerProchainEtat() override;
};

#endif

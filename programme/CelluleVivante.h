#ifndef CELLULEVIVANTE_H
#define CELLULEVIVANTE_H

#include "Cellule.h"

class CelluleVivante : public Cellule {
public:
    CelluleVivante(int x, int y);
    virtual ~CelluleVivante() override{}
    virtual bool calculerProchainEtat(int voisin) override;
    virtual void notifierObservateurs(int x, int y, bool etat) override;
};

#endif

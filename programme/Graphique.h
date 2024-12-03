#ifndef GRAPHIQUE_H
#define GRAPHIQUE_H

#include "Observers.h"

class ObservateurConcret2 : public Observer {
public:
    void update(int x, int y, bool etat) override;
};

#endif

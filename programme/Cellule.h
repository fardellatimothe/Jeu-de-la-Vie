#ifndef CELLULE_H
#define CELLULE_H

class Cellule {

private:
    int nbVoisinesVivantes;
    int x, y;    

public:
    Cellule(int x, int y);
    virtual void calculerProchainEtat() = 0;
    void setNbVoisinesVivantes(int nb);
    void notifierObservateurs(int x, int y, bool etat);
    int getx() const;
    int gety() const;
};

#endif

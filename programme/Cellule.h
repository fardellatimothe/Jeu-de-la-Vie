#ifndef CELLULE_H
#define CELLULE_H

class Cellule {

private:
    int nbVoisinesVivantes;
    int x, y;    

public:
    Cellule(int x, int y);
    virtual ~Cellule() {}
    
    virtual bool calculerProchainEtat(int voisin) = 0;
    void IncrementerVoisinesVivantes();
    virtual void notifierObservateurs(int x, int y, bool etat) = 0;
    int getx() const;
    int gety() const;
    int getVoisin() const;
};

#endif

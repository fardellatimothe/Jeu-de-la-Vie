#ifndef CONSOLE_H
#define CONSOLE_H

#include "Observers.h"
#include <vector>
#include <iostream>

using namespace std;

class Console : public Observer {
private:
    vector<vector<int>>* matrice;
public:
    void Update(int x, int y, int etat) override;
    Console(vector<vector<int>>* grid); 
    void AfficherMatrice() const;
};

#endif

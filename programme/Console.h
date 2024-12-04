#ifndef CONSOLE_H
#define CONSOLE_H

#include "Observers.h"
#include <vector>
#include <iostream>

using namespace std;

class Console : public Observer {
private:
    vector<vector<int>>* Matrice;
public:
    void update(int x, int y, int etat) override;
    Console(vector<vector<int>>* grid); 
    void Console::afficherMatrice() const;
};

#endif

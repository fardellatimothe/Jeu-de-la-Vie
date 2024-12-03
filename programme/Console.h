#ifndef CONSOLE_H
#define CONSOLE_H

#include "Observers.h"
#include <vector>
#include <iostream>

using namespace std;

class Console : public Observer {
private:
    vector<vector<bool>> Matrice;
public:
    void update(int x, int y, bool etat) override; 
};

#endif

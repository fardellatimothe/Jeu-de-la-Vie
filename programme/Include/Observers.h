#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void Update(int x, int y, int etat) = 0;
    virtual ~Observer() {}
};

#endif

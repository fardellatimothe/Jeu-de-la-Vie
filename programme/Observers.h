#ifndef OBSERVER_H
#define OBSERVER_H

class Observer {
public:
    virtual void update(int x, int y, bool etat) = 0;
    virtual ~Observer() {}
};

#endif

//
// Created by Hubert on 4/6/2019.
//

#include <vector>

#ifndef COMP345TEAM21_ABSTRACTGAME_H
#define COMP345TEAM21_ABSTRACTGAME_H


#include "Observer.h"

class Subject {
public:
    virtual void attach(Observer* p);
    virtual void detach(Observer* p);
    virtual void notify();
    Subject();
    ~Subject();
private:
    std::vector<Observer*>* observers;
};


#endif //COMP345TEAM21_ABSTRACTGAME_H

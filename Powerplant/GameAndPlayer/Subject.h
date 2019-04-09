//
// Created by alext on 4/9/2019.
//
#include <iostream>
#include <vector>
#include "Observer.h"
#include "Player.h"
#ifndef COMP345TEAM21_SUBJECT_H
#define COMP345TEAM21_SUBJECT_H

class Subject {
public:
    virtual void Attach(Observer* p);
    virtual void Detach(Observer* p);
    virtual void Notify();
    Subject();
    virtual ~Subject();
//private:
    std::vector<Observer *>* playerList;
//    std::list<Observer*>* observers;

};


#endif //COMP345TEAM21_SUBJECT_H

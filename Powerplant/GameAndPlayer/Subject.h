//
// Created by alext on 4/9/2019.
//
#ifndef COMP345TEAM21_SUBJECT_H
#define COMP345TEAM21_SUBJECT_H

#include <iostream>
#include <vector>
#include "Observer.h"
#include "Player.h"


class Subject {

public:
    virtual void Attach(Observer* p);
    virtual void Detach(Observer* p);
    virtual void Notify();
    virtual int display()=0;
//    virtual void
//    virtual void
    Subject();
    virtual ~Subject();
    std::vector<Observer *>* playerList;
};


#endif //COMP345TEAM21_SUBJECT_H

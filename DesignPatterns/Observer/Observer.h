//
// Created by Hubert on 4/6/2019.
//

#ifndef COMP345TEAM21_OBSERVER_H
#define COMP345TEAM21_OBSERVER_H


class Observer {
public:
    ~Observer();
    virtual void update() = 0;
protected:
    Observer();
};


#endif //COMP345TEAM21_OBSERVER_H

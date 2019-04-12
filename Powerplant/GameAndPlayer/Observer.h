//
// Created by alext on 4/9/2019.
//

#ifndef COMP345TEAM21_OBSERVER_H
#define COMP345TEAM21_OBSERVER_H


class Observer {
public:
    ~Observer();
    virtual void Update(int i) = 0;
protected:
    Observer();
};



#endif //COMP345TEAM21_OBSERVER_H

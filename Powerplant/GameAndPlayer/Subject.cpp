//
// Created by alext on 4/9/2019.
//
#include "Subject.h"
Subject::Subject(){
    playerList = new std::vector<Observer*>;
}
Subject::~Subject(){
    delete playerList;
}
void Subject::Attach(Observer* o){
    playerList->push_back(o);
};
void Subject::Detach(Observer* o){
    playerList->erase(std::remove(playerList->begin(),playerList->end(), o), playerList->end());
};
void Subject::Notify(){
     int j =0;
    for (std::vector<Observer*>::iterator i = playerList->begin(); i != playerList->end(); ++i) {
        (*i)->Update(j);
        j++;
    }
    display();
};

#include "Subject.h"

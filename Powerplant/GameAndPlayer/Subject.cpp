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
    for (std::vector<Observer *>::iterator i = playerList->begin(); i != playerList->end(); ++i)
        (*i)->Update();
};

#include "Subject.h"

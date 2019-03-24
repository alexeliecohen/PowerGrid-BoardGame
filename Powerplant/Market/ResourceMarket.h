
//
// Created by alext on 2/21/2019.
//

#ifndef POWERPLANT_RESOURCEMARKET_H
#define POWERPLANT_RESOURCEMARKET_H


#include "../Resource/Resource.h"
#include "Market.h"


static int RESSUPLYMARKET[5][3][4] = {{{3,2,1,1},{4,2,2,1},{3,4,3,1}},{{4,2,1,1},{5,3,2,1},{3,4,3,1}},
                                      {{5,3,2,1},{6,4,3,2},{4,5,4,2}},{{5,4,3,2},{7,5,3,3},{5,6,5,2}},
                                      {{7,5,3,2},{9,6,5,3},{6,7,6,3}}};

class ResourceMarket: Market {
private:
    Resource myResources[10];
public:
    ResourceMarket() {
//        for (int i = 0; i < ; ++i) {
//
//        }
    }


};


#endif //POWERPLANT_RESOURCEMARKET_H

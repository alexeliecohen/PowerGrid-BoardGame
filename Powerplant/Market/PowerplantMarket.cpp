<<<<<<< HEAD
//
// Created by alext on 2/27/2019.
//

#include "PowerplantMarket.h"

PowerplantMarket::PowerplantMarket(Deck &myDeck) {
//    replaceCurrentMarket();
//    replaceFutureMarket();
}
ostream& operator<<(ostream& stream,PowerplantMarket p1) {
    for (int i = 0; i < 4; ++i) {
        stream << i <<  ":" << p1.currentMarket[i] << endl;
    }
    return stream;
}
=======
//
// Created by alext on 2/27/2019.
//

#include "PowerplantMarket.h"
>>>>>>> ba322169f69d5c08b2ff60172d0b5f3022c7a0e2

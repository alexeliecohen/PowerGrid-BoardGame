#include <iostream>
#include "HousesAndCities/Houses.h"
#include "Card/Powerplant.h"
#include "Card/Deck.h"
#include "Resource/Resource.h"


int main() {
////    Houses h(3,houseColor::Black,"AlexC");
//    std::cout << "Hello, World!" << std::endl;
//    Houses i = h;
//    cout << h << endl;
////    ++h;
//    cout << h << endl;
//
//    cout << "i: " << h << endl;
//
////    Resource c(12,11,"Nuclear");
////    Resource d = c;
////    c.;
////    ++
//
//    Resource r(4,1,"coal");
//
////    Powerplant p(13,2,1,c);
//    cout << r << endl;
////    delete c;
    Deck d;
//    std::cout<<d<<endl;
//    cout << "\n\n";

    d.shuffle();
    std::cout << d <<endl;




    return 0;
}
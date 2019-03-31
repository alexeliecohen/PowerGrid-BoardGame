#include <iostream>
#include "HousesAndCities/Houses.h"
#include "Card/Powerplant.h"
#include "Card/Deck.h"
#include "Resource/Resource.h"
#include "GameAndPlayer/Player.h"


int main() {
    int numbHouses = 132;

    //Creating resources
    Resource r1 = Resource(2, 3, "Coal");
    Resource r2 = Resource(4, 6, "Oil");
    Resource r3 = Resource(5, 5, "Nuclear");
    Resource r4 = Resource(7, 10, "Garbage");


    Deck d;
    cout << "Showing deck of cards:" << endl;
    cout << d << endl;

    cout << "Showing cards after shuffling" << endl;
    d.shuffle();
    cout << d << endl;


    cout << "Removing Deck of cards" << endl;
    Card *c1 = d.removeCard(2);
    Card *c2 = d.removeCard(5);
    Card *c3 = d.removeCard(10);
    Card *c4 = d.removeCard(11);
    Card *c5 = d.removeCard(12);
    Card *c6 = d.removeCard(13);
    Card *c7 = d.removeCard(14);
    Card *c8 = d.removeCard(15);
    Card *c9 = d.removeCard(16);
    Card *c10 = d.removeCard(17);
    Card *c11 = d.removeCard(18);
    Card *c12 = d.removeCard(19);

    cout << "Displaying cards after removing" << endl;
    std::cout << d << endl;
    Player p1 = Player();
    Player p2 = Player();
    Player p3 = Player();
    Player p4 = Player();
    Player p5 = Player();
    Player p6 = Player();

    cout << "Adding powerplants to player class" << endl;
    p1.addPowerplant(*dynamic_cast<Powerplant *>(c1));
    p1.addPowerplant(*dynamic_cast<Powerplant *>(c2));
    p2.addPowerplant(*dynamic_cast<Powerplant *>(c3));
    p2.addPowerplant(*dynamic_cast<Powerplant *>(c4));
    p3.addPowerplant(*dynamic_cast<Powerplant *>(c5));
    p3.addPowerplant(*dynamic_cast<Powerplant *>(c6));
    p4.addPowerplant(*dynamic_cast<Powerplant *>(c7));
    p4.addPowerplant(*dynamic_cast<Powerplant *>(c8));
    p5.addPowerplant(*dynamic_cast<Powerplant *>(c9));
    p5.addPowerplant(*dynamic_cast<Powerplant *>(c10));
    p6.addPowerplant(*dynamic_cast<Powerplant *>(c11));
    p6.addPowerplant(*dynamic_cast<Powerplant *>(c12));

    cout << p1 << endl;
    p1.removePowerplant(*dynamic_cast<Powerplant *>(c1));
    cout << p1 << endl;
    Houses houseArray[numbHouses];
//    h1 = Houses(6,p1.getMyHouseColor(),p1.getPlayerName(),"Montreal");
//    Houses h2 = Houses(10,p1.getMyHouseColor(),p1.getPlayerName(),"Ottowa");
//    Houses h3 = Houses(4,p2.getMyHouseColor(),p2.getPlayerName(),"Quebec");
//    Houses h4 = Houses(4,p2.getMyHouseColor(),p2.getPlayerName(),"Toronto");
//    p1.addHouses(h1);

    for (int i = 0; i < numbHouses; ++i) {
        if (i % MAXNUMBERPLAYERS == 0) {
            houseArray[i] = Houses(rand(), p1.getMyHouseColor(), p1.getPlayerName());
            p1.addHouses(houseArray[i]);
        } else if (i % MAXNUMBERPLAYERS == 1) {
            houseArray[i] = Houses(rand(), p2.getMyHouseColor(), p2.getPlayerName());
            p2.addHouses(houseArray[i]);
        } else if (i % MAXNUMBERPLAYERS == 2) {
            houseArray[i] = Houses(rand(), p3.getMyHouseColor(), p3.getPlayerName());
            p3.addHouses(houseArray[i]);

        } else if (i % MAXNUMBERPLAYERS == 3) {
            houseArray[i] = Houses(rand(), p4.getMyHouseColor(), p4.getPlayerName());
            p4.addHouses(houseArray[i]);
        } else if (i % MAXNUMBERPLAYERS == 4) {
            houseArray[i] = Houses(rand(), p5.getMyHouseColor(), p5.getPlayerName());
            p5.addHouses(houseArray[i]);
        } else {
            houseArray[i] = Houses(rand(), p6.getMyHouseColor(), p6.getPlayerName());
            p6.addHouses(houseArray[i]);
        }
    }
    p1.addElektro(12);
    p2.addElektro(34);
    p3.addElektro(76);
    p4.addElektro(52);
    p5.addElektro(89);
    p6.addElektro(24);

    p1.addCoal(6);
    p2.addCoal(4);
    p3.addCoal(2);
    p4.addCoal(9);
    p5.addCoal(1);
    p6.addCoal(7);

    p1.addGarbage(3);
    p2.addGarbage(4);
    p3.addGarbage(7);
    p4.addGarbage(8);
    p5.addGarbage(3);
    p6.addGarbage(1);


    p1.addUranium(5);
    p2.addUranium(6);
    p3.addUranium(3);
    p4.addUranium(1);
    p5.addUranium(8);
    p6.addUranium(9);


    p1.addOil(1);
    p2.addOil(5);
    p3.addOil(7);
    p4.addOil(8);
    p5.addOil(3);
    p6.addOil(1);


    cout << "Displaying player 1" << endl;
    cout << p1 << endl;
    cout << "Displaying player 2" << endl;
    cout << p2 << endl;

    cout << "Displaying player 3" << endl;
    cout << p3 << endl;

    cout << "Displaying player 4" << endl;
    cout << p4 << endl;

    cout << "Displaying player 5" << endl;
    cout << p5 << endl;

    cout << "Displaying player 6" << endl;
    cout << p6 << endl;


    return 0;
}
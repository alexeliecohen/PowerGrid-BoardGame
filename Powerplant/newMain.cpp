//
// Created by alext on 3/19/2019.
//

#include "GameAndPlayer/Player.h"
#include "Card/Deck.h"
#include "Card/Powerplant.h"

int main() {
    Deck D =  Deck();




//    cout << D << endl;

    Card *c = D.removeCard(0);
    Card *c1 = D.removeCard(1);
    Card *c2 = D.removeCard(2);
    Card *c3= D.removeCard(3);
//    cout << *c  << endl;
//    cout << *c1 << endl;
//    cout << *c2 << endl;
//    cout << *c3 << endl;



    Player p1 = Player("Alex");
    Player p2 = Player("John");
    Player p3 = Player("Tina");
    Player p4 = Player("Fey");


    Powerplant pw1 = *dynamic_cast<Powerplant*>(c);
    Powerplant pw2 = *dynamic_cast<Powerplant*>(c1);
    Powerplant pw3 = *dynamic_cast<Powerplant*>(c2);
    Powerplant pw4 = *dynamic_cast<Powerplant*>(c3);
//
//    cout << pw1 << endl;
//    cout << pw2 << endl;
//    cout << pw3 << endl;
//    cout << pw4 << endl;


    p1.addPowerplant(pw3);
    p2.addPowerplant(pw4);
    p3.addPowerplant(pw1);
    p4.addPowerplant(pw2);




    std::vector<Player> Playerlist;
    Playerlist.push_back(p1);
    Playerlist.push_back(p2);
    Playerlist.push_back(p3);
    Playerlist.push_back(p4);

    for (int i = 0; i < Playerlist.size(); ++i) {
        cout << Playerlist[i] << endl;
    }

    sort(Playerlist.begin(),Playerlist.begin()+Playerlist.size());



    cout << endl << endl << "after sorting....."<< endl;


    for (int i = 0; i < Playerlist.size(); ++i) {
        cout << Playerlist[i] << endl;
    }



    cout << Playerlist.back() << endl;
    return 0;
}


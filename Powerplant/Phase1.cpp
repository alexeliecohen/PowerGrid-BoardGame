//
// Created by alext on 3/19/2019.
//

#include "GameAndPlayer/Player.h"
#include "Card/Deck.h"
#include "Card/Powerplant.h"
#include "Market/PowerplantMarket.h"
#include "GameAndPlayer/Game.h"

//int main() {
//    Deck D =  Deck();
//
//    Card *c = D.removeCard(0);
//    Card *c1 = D.removeCard(1);
//    Card *c2 = D.removeCard(2);
//    Card *c3= D.removeCard(3);
//
//
//    Player p1 = Player("Alex");
//    Player p2 = Player("John");
//    Player p3 = Player("Tina");
//    Player p4 = Player("Fey");
//
//
//    Powerplant pw1 = *dynamic_cast<Powerplant*>(c);
//    Powerplant pw2 = *dynamic_cast<Powerplant*>(c1);
//    Powerplant pw3 = *dynamic_cast<Powerplant*>(c2);
//    Powerplant pw4 = *dynamic_cast<Powerplant*>(c3);
////
////    cout << pw1 << endl;
////    cout << pw2 << endl;
////    cout << pw3 << endl;
////    cout << pw4 << endl;
//
//
//    p1.addPowerplant(pw3);
//    p2.addPowerplant(pw4);
//    p3.addPowerplant(pw1);
//    p4.addPowerplant(pw2);
//
//
//
//
//    std::vector<Player> Playerlist;
//    Playerlist.push_back(p1);
//    Playerlist.push_back(p2);
//    Playerlist.push_back(p3);
//    Playerlist.push_back(p4);
//
//    for (int i = 0; i < Playerlist.size(); ++i) {
//        cout << Playerlist[i] << endl;
//    }
//
//
////    Playerlist.erase(Playerlist.begin()+1);
//
//    sort(Playerlist.begin(),Playerlist.end());
//    reverse(Playerlist.begin(),Playerlist.end());
////
////
////s
////    cout << endl << endl << "after sorting....."<< endl;
//
//
//    cout << "============================================================" << endl;
//    cout << "============================================================" << endl;
//    cout << "============================================================" << endl;
//    cout << "============================================================" << endl;
//    cout << "============================================================" << endl;
//    cout << "============================================================" << endl;
//
//    for (int i = 0; i < Playerlist.size(); ++i) {
//        cout << Playerlist[i] << endl;
//    }
//
//
//
//    cout << Playerlist.back() << endl;
//    return 0;
//}

//Powerplant &Auction(Player& currentBidder,PowerplantMarket pMarket) {
//    string bid;
//    int marketSize = pMarket.getSize();
//    do {
//        cout << currentBidder->getPlayerName() << "Please enter a number to pick a powerplant" << endl;
//        cout << pMarket << endl;
//        cin >> bid;
//        //if the input was not a valid integer,or the number picked was larger/less than the powerplant size
//        //output error clear buffer and restart.
//        if (!isValidInteger(bid) || stoi(bid) > marketSize || stoi(bid) < 0) {
//            cout << "Error: Entered wrong value for bid, please enter a correct powerplant number" << endl;
//            cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        }
//    } while (!isValidInteger(bid) || stoi(bid) > marketSize - 1 || stoi(bid) < 0);
//    int val = stoi(bid);
//    cout << "hello" << endl;
//    Powerplant p1 = pMarket.removePowerplant(val);
//    cout << "hello" << endl;
//    cout << p1 << endl;
//    return p1;
//}




int main() {
//    Deck d;

//    Game g =  Game();

//    g.Phase1();
    Deck d;
    Player p1 = Player("AlexC");
    Player p2 = Player("ThomasB");
    p1.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    p1.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    d.shuffle();
    p2.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    p2.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    cout << p1 << endl;
    cout << p2 << endl;
}



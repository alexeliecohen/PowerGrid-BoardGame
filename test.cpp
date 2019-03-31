//
// Created by Hubert on 3/31/2019.
//

#include "Powerplant/Card/Deck.h"
#include "Powerplant/GameAndPlayer/Player.h"
#include "Powerplant/GameAndPlayer/Game.h"

int main() {
    Deck d;
    Player p1 = Player("AlexC");
    Player p2 = Player("ThomasB");
    p1.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    p1.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    d.shuffle();
    p2.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    p2.addPowerplant(*dynamic_cast<Powerplant*>(d.removeCard()));
    p1.addCoal(1);
    p1.addGarbage(1);
    p1.addOil(1);
    p1.addUranium(1);
    cout << p1;
    p1.powerCities();

    return 0;
}


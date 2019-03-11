//
// Created by alext on 3/6/2019.
//

#include "Deck.h"



std::vector<Card*> Deck::CardDeck;
//int size = Deck::CardDeck;

Deck::Deck() {

    CardDeck.push_back(new Step13());

    CardDeck.push_back(new Powerplant(4,2,1,"Coal"));
    CardDeck.push_back(new Powerplant(8,3,2,"Coal"));
    CardDeck.push_back(new Powerplant(10,2,2,"Coal"));
    CardDeck.push_back(new Powerplant(15,2,3,"Coal"));
    CardDeck.push_back(new Powerplant(20,3,5,"Coal"));
    CardDeck.push_back(new Powerplant(25,2,5,"Coal"));
    CardDeck.push_back(new Powerplant(31,3,6,"Coal"));
    CardDeck.push_back(new Powerplant(36,3,7,"Coal"));
    CardDeck.push_back(new Powerplant(42,2,6,"Coal"));

    //Oil Powerplants
    CardDeck.push_back(new Powerplant(3,2,1,"Oil"));
    CardDeck.push_back(new Powerplant(7,3,2,"Oil"));
    CardDeck.push_back(new Powerplant(9,1,1,"Oil"));
    CardDeck.push_back(new Powerplant(16,2,3,"Oil"));
    CardDeck.push_back(new Powerplant(26,2,5,"Oil"));
    CardDeck.push_back(new Powerplant(32,3,6,"Oil"));
    CardDeck.push_back(new Powerplant(35,1,5,"Oil"));
    CardDeck.push_back(new Powerplant(40,2,6,"Oil"));

    CardDeck.push_back(new Powerplant(5,2,1,"Hybrid"));
    CardDeck.push_back(new Powerplant(12,2,2,"Hybrid"));
    CardDeck.push_back(new Powerplant(21,2,4,"Hybrid"));
    CardDeck.push_back(new Powerplant(29,1,4,"Hybrid"));
    CardDeck.push_back(new Powerplant(29,3,7,"Hybrid"));

    //Garbage Powerplants
    CardDeck.push_back(new Powerplant(6,1,1,"Garbage"));
    CardDeck.push_back(new Powerplant(14,2,2,"Garbage"));
    CardDeck.push_back(new Powerplant(19,2,3,"Garbage"));
    CardDeck.push_back(new Powerplant(24,2,4,"Garbage"));
    CardDeck.push_back(new Powerplant(30,3,6,"Garbage"));
    CardDeck.push_back(new Powerplant(38,3,7,"Garbage"));

    //Nuclear Powerplants
    CardDeck.push_back(new Powerplant(11,1,2,"Nuclear"));
    CardDeck.push_back(new Powerplant(17,1,2,"Nuclear"));
    CardDeck.push_back(new Powerplant(23,1,3,"Nuclear"));
    CardDeck.push_back(new Powerplant(28,1,4,"Nuclear"));
    CardDeck.push_back(new Powerplant(34,1,5,"Nuclear"));
    CardDeck.push_back(new Powerplant(39,1,6,"Nuclear"));

    //Ecological Powerplants
    CardDeck.push_back(new Powerplant(13,0,1,"Ecological"));
    CardDeck.push_back(new Powerplant(18,0,2,"Ecological"));
    CardDeck.push_back(new Powerplant(22,0,2,"Ecological"));
    CardDeck.push_back(new Powerplant(27,0,3,"Ecological"));
    CardDeck.push_back(new Powerplant(33,0,4,"Ecological"));
    CardDeck.push_back(new Powerplant(37,0,4,"Ecological"));
    CardDeck.push_back(new Powerplant(44,0,5,"Ecological"));


}
Deck::~Deck() {
    for (int i = 0; i < CardDeck.size(); ++i) {
        delete CardDeck[i];
    }
}


void Deck::swapCards(Card* card1,Card* card2) {
    Card temp = *card1;
    std::cout << temp << std::endl;

//    std::cout << *card1 << std::endl;
//    std::cout << *card2 << std::endl;
    *card1 = *card2;
    *card2 = temp;
    std::cout << *card1 << std::endl;
    std::cout << *card2 << std::endl;

}



void Deck::shuffle() {
    int random=0;
    for (int i = 0; i < CardDeck.size(); ++i) {
        int random = rand()% CardDeck.size();
        iter_swap(CardDeck.begin()+i,CardDeck.begin()+random);
    }
}

std::ostream& operator<<(std::ostream& stream,Deck& myDeck) {
//    for (int i = 0; i < myDeck.CardDeck.size(); ++i) {
//        stream << *(myDeck.CardDeck[i])<< std::endl;
////        stream << i << std::endl;
//    }

//
//    for (const auto& str: myDeck)
//        std::cout << *str << std::endl;
//
//    vector<*>::iterator iter;
//    for (iter = firstname_list.begin(); iter != firstname_list.end(); ++iter)
//        std::cout << **iter;
    for (std::vector<Card*>::iterator it = myDeck.CardDeck.begin(); it != myDeck.CardDeck.end(); ++it) {
        stream << **it << std::endl;
//        stream << "hello" << std::endl;
    }

    return stream;
}
//Card& Deck::removeCard(Card& myCard) {
//    Card *someCard;
//    std::vector<Card *>::iterator position = std::find(CardDeck.begin(), CardDeck.end(), myCard);
//    if (position != CardDeck.end()) // == myVector.end() means the element was not found {
////        someCard = CardDeck.at(position);
//
//        CardDeck.erase(position);
//}
//
//
//}

Card* Deck::removeCard(int pos) {
    Card *c1 = CardDeck[pos];
    CardDeck.erase(CardDeck.begin() + pos);
    return c1;
}

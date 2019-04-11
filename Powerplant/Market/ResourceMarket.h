
#include <iostream>
#include <string>

#ifndef RESOURCEMARKET_H_
#define RESOURCEMARKET_H_

    static int RESSUPLYMARKET[5][3][4] = {{{3, 2, 1, 1}, {4, 2, 2, 1}, {3, 4, 3, 1}},
                                          {{4, 2, 1, 1}, {5, 3, 2, 1}, {3, 4, 3, 1}},
                                          {{5, 3, 2, 1}, {6, 4, 3, 2}, {4, 5, 4, 2}},
                                          {{5, 4, 3, 2}, {7, 5, 3, 3}, {5, 6, 5, 2}},
                                          {{7, 5, 3, 2}, {9, 6, 5, 3}, {6, 7, 6, 3}}};

    class ResourceMarket {
    private:
        //Attributes
        int oil;
        int coal;
        int garbage;
        int uranium;
        //[Number Of Players] [Game Phase Number] [RESOURCE # - 1 2 3 4]
        int RESSUPLYMARKET[5][3][4];

    public:
        //Methods
        void addOil();

        void addOil(int amt);

        void removeOil();

        void removeOil(int amt);

        int getOil();

        void addCoal();

        void addCoal(int amt);

        void removeCoal();

        void removeCoal(int amt);

        int getCoal();

        void addGarbage();

        void addGarbage(int amt);

        void removeGarbage();

        void removeGarbage(int amt);

        int getGarbage();

        void addUranium();

        void addUranium(int amt);

        void removeUranium();

        void removeUranium(int amt);

        int getUranium();

        //Get Price of next
        int getCoalPrice();

        int getOilPrice();

        int getGarbagePrice();

        int getUraniumPrice();

        //Constructors / Destructors
        ResourceMarket();

        virtual ~ResourceMarket();

        //Display
        void printResourceMarketStock();

        void printResourceMarket();

        //Re-supply at end of turn
        void resupplyMarket(int numOfPlayers, int gamePhase);

        //Overload <<


    };

#endif /* RESOURCEMARKET_H_ */

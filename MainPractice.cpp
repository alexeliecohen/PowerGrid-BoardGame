//
// Created by alext on 3/19/2019.
//
#include <iostream>
#include <cstring>
#include "/Powerplant/Market/"
bool isParam(std::string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
void determineNumbPlayers() {
    int numbPlayer = 0;
    std::string temp;
    do {
        std::cout << std::endl << "Please enter the number of players (between 2-6 inclusive) for the game:"<< std::endl;
        std::cin >> temp;
        if (!isParam(temp)) {
            std::cout << "Error Input a string" << std::endl;
            continue;
        }
        numbPlayer = std::stoi(temp);

        if (numbPlayer < 2 || numbPlayer > 6) {
            std::cout << "Invalid: The number of players must be between 2-6 inclusive";
        }
    } while (numbPlayer < 2 || numbPlayer > 6);
}

void determinePlayerOrder() {

}

int main() {



}
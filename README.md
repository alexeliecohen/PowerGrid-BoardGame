
Welcome to the Powergrid board game! 
This game involves using a Game Board space for which players are assigned to specific regions of the board for which the player can 
buy cities and places houses, buy resources/powerplants from the market and use them to power cities on the game board
buy resources and 
poerpl

Mapfiles: 
The files used to generate to generate maps to create the gameboard

FileReader:

The File Reader Directory is responsible for generating the game board object reprsented as Map. The File Reader imports a .Map file 
for importing a .Map file in the class. It first does so by checking if the Map is a valid one, if so, then the map is generated using
the Map class. Hence creating the game board Object

Map:
Map Class is responsible for handling the gameboard itself by looking for the players current position in each city, as well as the 
adjacent cities to each player. The implenetation uses Adjacency listing for storing values and our own methods for DFS and BFS algorithms. 

Powerplant:
Powerplant class is responsible for the game implementation. That is the players, the deck of cards (including step 3 card,powerplant,and
summary cards), the resource/powerplant markets,as well as the phase and step implementations for the game.  

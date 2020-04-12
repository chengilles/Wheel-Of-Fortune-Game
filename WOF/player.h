#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
    char* name;
    int currentTurnMoney = 0;
    int totalMoney = 0;
} Player;

//Returns the number of players.
int getPlayersNumber();

//Returns the names of the players.
char* getPlayerNames();

//Returns a random integer to decide which player will start the first Turn.
int chooseFirstPlayer();

//Returns an Array of Pointers to a structure Player.
Player** initPlayers();

#endif /* PLAYER_H */


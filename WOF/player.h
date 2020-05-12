#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "io.h"
#include "init.h"

typedef struct{
    char* name;
    int currentTurnMoney;
    int totalMoney;
    bool canBuyVowel;
} Player;

//Returns the number of players.
int getPlayersNumber();

//Returns a random integer to decide which player will start the first Turn.
int chooseFirstPlayer(int playersNumber);

Player* createPlayer(int index);

//Returns an Array of Pointers to a structure Player.
Player** initPlayers(int playersNumber);

void freePlayers(Player** players, int playersNumber);

#endif /* PLAYER_H */

#ifndef TURN_H
#define TURN_H
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


// Selects a new puzzle, set money to 0, print winner.
void endRound(Player** players, int playersNumber);

// Displays current player name + his money.
void displayCurrentPlayer(Player* p);

// Displays current round.
void displayCurrentRound(int round);

// Adds money to player.
void addMoney(Player* p, int money);

// Displays the loading bar.
void loadingBar();

#endif /* TURN_H */
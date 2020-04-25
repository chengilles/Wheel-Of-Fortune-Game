#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
//#include "player.h"
#include "turn.h"
#include "wheel.h"

int main() {
    int playersNumber;
    char** puzzles;
    Player** players;

    displayGreetings();
    displayRules();

    puzzles = getPuzzles();
    players = initPlayers();

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
//#include "player.h"
#include "turn.h"
#include "wheel.h"

int main() {
    srand(time(NULL));

    char** puzzles;
    Player** players;
    int playersNumber;
    int currentPlayer;

    /*displayGreetings();
    displayRules();*/

    //puzzles = getPuzzles();
    playersNumber = getPlayersNumber();
    //players = initPlayers(playersNumber);

    currentPlayer = chooseFirstPlayer(playersNumber);
    printf("%d", currentPlayer);

    return 0;
}


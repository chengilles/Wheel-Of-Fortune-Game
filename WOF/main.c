#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
//#include "player.h"
#include "turn.h"
#include "wheel.h"

int main() {
    int playersNumber;

    /*displayGreetings();
    displayRules();*/
    //getPuzzles();
    playersNumber = getPlayersNumber();
    getPlayerNames(playersNumber);

    return 0;
}


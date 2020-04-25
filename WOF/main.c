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
    char* currentPuzzle;

    Player** players;
    int playersNumber;
    int currentPlayer;
    int round = 0;
    bool puzzleSolved = false;

    displayGreetings();
    displayRules();

    puzzles = getPuzzles();
    playersNumber = getPlayersNumber();
    players = initPlayers(playersNumber);

    currentPlayer = chooseFirstPlayer(playersNumber);

    do {
        displayCurrentRound(round+1);
        currentPuzzle = puzzles[round];

        for(int i = 0; i<playersNumber;i++)
            displayCurrentPlayer(players[i]);
        printf("\n\n--------------------------------------\n\n");

        while (!puzzleSolved) {
            printf("\nYour turn: ");
            displayCurrentPlayer(players[currentPlayer]);
            //Player plays
            currentPlayer = (currentPlayer+1) % playersNumber;
        }

        round++;
    } while (round < 3);

    return 0;
}


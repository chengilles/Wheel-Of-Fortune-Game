#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
//#include "player.h"
#include "turn.h"
#include "wheel.h"

int main() {
    srand(time(NULL));

    char* currentPuzzle;
    char** puzzles;

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
        displayCurrentRound(round + 1);
        for(int i = 0; i<playersNumber;i++)
            displayCurrentPlayer(players[i]);

        currentPuzzle = puzzles[round];
        hidePuzzle(currentPuzzle);

        int a = 0;
        while (a++< 3) {
            printf("Your turn: ");
            displayCurrentPlayer(players[currentPlayer]);
            //Player plays
            currentPlayer = (currentPlayer+1) % playersNumber;
        }

        round++;
    } while (round < 3);

    return 0;
}
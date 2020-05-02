#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
#include "player.h"
#include "turn.h"
#include "wheel.h"

int main() {
    srand(time(NULL));

    char guess;
    char* currentPuzzle;
    char** puzzles;
    Player** players;

    int wheel[24] = wheelInit;
    int round = 0, wheelValue, playersNumber, currentPlayer, occ;
    bool puzzleSolved = false, playerTurn = false, correctCond = false;

    displayLogo();
    displayGreetings();
    displayRules();

    puzzles = getPuzzles();
    playersNumber = getPlayersNumber();
    players = initPlayers(playersNumber);
    currentPlayer = chooseFirstPlayer(playersNumber);   
     
    while (round++ < 3) {
        displayCurrentRound(round);
        for (int i = 0; i < playersNumber; i++)
            displayCurrentPlayer(players[i]);

        currentPuzzle = _strdup(puzzles[round-1]);
        hidePuzzle(currentPuzzle);

        while (!puzzleSolved) {
            playerTurn = true;

            while (playerTurn) {
                printf("Your turn: ");
                displayCurrentPlayer(players[currentPlayer]);
                wheelValue = spinWheel(wheel);

                switch (wheelValue) {
                 case -1:
                     printf("You landed on Lose Turn... :(\n\n");
                     playerTurn = false;
                     break;
                 case 0:
                     printf("You landed on Bankrupt... :(\n\n");
                     players[currentPlayer]->currentTurnMoney = 0;
                     playerTurn = false;
                     break;
                 case 1:
                     printf("You landed on Extra Turn !\n\n");
                     currentPlayer = (--currentPlayer) % playersNumber;
                     break;
                 default:
                     printf("You landed on %d$ wedge\n", wheelValue);
                     do {
                         correctCond = false;
                         if(!players[currentPlayer]->hasPlayed)
                            printf("Enter a consonant: ");
                         else
                             printf("Enter a consonant or buy a vowel (-250$): ");
                         scanf_s(" %c", &guess);

                         //If if is the first turn of the player and he enters a vowel
                         if (!players[currentPlayer]->hasPlayed && isVowel(guess)) {
                             printf("%c is not a consonant, and you don't have enough money to buy a vowel!\n", guess);
                             correctCond = true;
                         }
                         else if (players[currentPlayer]->hasPlayed && isVowel(guess) && players[currentPlayer]-> currentTurnMoney < 250){
                             printf("You don't have enough money to buy a vowel!\n");
                             correctCond = true;
                         }
                     } while (correctCond);  //!players[currentPlayer]->hasPlayed&& isVowel(guess));

                     if ((playerTurn = occ = getOccurrence(puzzles[round-1], currentPuzzle, guess))) {
                         printf("Congratulations, %c is present %d times in the puzzle\n", guess, occ);
                         addMoney(players[currentPlayer], isVowel(guess) ? ((occ * wheelValue) - 250) : (occ * wheelValue));
                         printf("Your new balance: %d$\n\n", players[currentPlayer]->currentTurnMoney);
                     }
                     else {
                         printf("%c is not contained in the puzzle\n\n", guess);
                     }
                     displayPuzzle(currentPuzzle);
                     players[currentPlayer]->hasPlayed = true;
                     break;
                }               
            }   
            currentPlayer = (++currentPlayer) % playersNumber;
        }
    }
    return 0;
}
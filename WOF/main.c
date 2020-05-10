#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
#include "player.h"
#include "turn.h"
#include "wheel.h"

int main() {
    srand(time(NULL));
    //loadingBar();
    char guess;
    char* currentPuzzle;
    char** puzzles;
    Player** players;

    int wheel[24] = wheelInit;
    int round = 0, wheelValue, playersNumber, currentPlayer, occ = 0, firstPlayer;
    bool puzzleSolved, playerTurn = false, correctCond;

    displayLogo();
    displayGreetings();
    displayRules();

    puzzles = getPuzzles();
    playersNumber = getPlayersNumber();
    players = initPlayers(playersNumber);
    firstPlayer = chooseFirstPlayer(playersNumber);
     
    while (round++ < 3) {
        puzzleSolved = false;
        currentPlayer = firstPlayer;
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
                //loadingBar();
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
                     playerTurn = false;
                     break;
                 default:
                     printf("You landed on %d$ wedge\n", wheelValue);

                     if (onlyVowelsLeft(puzzles[round-1], currentPuzzle))
                         players[currentPlayer]->canBuyVowel=true;

                     //README 
                     correctCond = true;
                     if (strcmp(puzzles[round - 1], currentPuzzle)==0) {
                         correctCond = false;
                         occ = -1;
                     }                         


                     while (correctCond) {
                         correctCond = false;
                         if (!players[currentPlayer]->canBuyVowel)
                             printf("Enter a consonant: ");
                         else
                             printf("Enter a consonant or buy a vowel (-250$): ");
                         scanf_s(" %c", &guess);

                         //If if is the first turn of the player and he enters a vowel
                         if (!players[currentPlayer]->canBuyVowel && isVowel(guess)) {
                             printf("%c is not a consonant!\n", guess);
                             correctCond = true;
                         }
                     }

                     if (occ != -1) {
                         if ((playerTurn = occ = getOccurrence(puzzles[round - 1], currentPuzzle, guess))) {
                             printf("Congratulations, %c is present %d times in the puzzle\n", guess, occ);
                             addMoney(players[currentPlayer], isVowel(guess) ? ((occ * wheelValue) - 250) : (occ * wheelValue));
                             printf("Your new balance: %d$\n\n", players[currentPlayer]->currentTurnMoney);
                         }
                         else {
                             printf("%c is not contained in the puzzle\n\n", guess);
                         }
                     }
                     displayPuzzle(currentPuzzle);
                     players[currentPlayer]->canBuyVowel = true;

                     //If players find occurences then he can guess the puzzle
                     if (occ!=0) {
                         if (occ>=0) {
                             do {
                                 printf("Do you want to guess the puzzle ? [Y/N]\n");
                                 scanf(" %c", &guess);
                             } while (guess != 'Y' && guess != 'N'); 
                             flushInput();
                         }
                         else {
                             guess = 'Y';
                         }

                         if (guess == 'Y') {
                             printf("Enter your guess: ");
                             char* puzzleGuess = _strdup(my_gets(BUFFER_SIZE));

                             if (strcmp(puzzleGuess, puzzles[round - 1]) == 0) {
                                 printf("Congratulations %s ! You have won round %d !\n\n", players[currentPlayer]->name, round);
                                 firstPlayer = (++firstPlayer) % playersNumber;
                                 puzzleSolved = true;

                                 for (int i = 0; i < playersNumber; i++) {
                                     players[i]->canBuyVowel = false;
                                     players[i]->totalMoney += (i == currentPlayer) ? players[i]->currentTurnMoney : 0;
                                     players[i]->currentTurnMoney = 0;
                                 }                                     
                             }
                             else {
                                 printf("I am afraid you fucked up frr\n\n");
                             }
                             playerTurn = false;
                         }
                         else {
                             printf("OK, let's continue!");
                             displayPuzzle(currentPuzzle);
                         }
                     }
                     break;
                }               
            } 
            currentPlayer = (++currentPlayer) % playersNumber;
        }
        printf("\n---END OF ROUND %d---", round);
        endRound(players, playersNumber);
    }
    printf("\n---GAME STANDING---");
    endRound(players, playersNumber);
    printf("Thanks for playing !\n\n\n");

    return 0;
}
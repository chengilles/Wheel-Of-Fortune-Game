#include <stdio.h>
#include <stdlib.h>
#include "init.h"
#include "io.h"
#include "player.h"
#include "game.h"

int main() {
    srand(time(NULL));

    char guess;
    char* currentPuzzle = NULL;
    char* puzzleGuess = NULL;
    char** puzzles;
    Player** players;

    int wheel[24] = wheelInit;
    int round = 0, wheelValue, playersNumber, currentPlayer, occ = 0, firstPlayer;
    bool puzzleSolved, playerTurn = false, correctCond;

    displayLogo();
    displayGreetings();
    displayRules();

    printf("\033[1;36m####################### INIT #######################\033[0m\n\n");
    puzzles = getPuzzles();
    playersNumber = getPlayersNumber();
    players = initPlayers(playersNumber);
    firstPlayer = chooseFirstPlayer(playersNumber);
     
    printf("\033[1;36m\n################ LET THE GAME START ################\033[0m\n");

    while (round++ < 3) {
        puzzleSolved = false;
        currentPlayer = firstPlayer;
        displayCurrentRound(round);
      
        if ((currentPuzzle = strdup(puzzles[round - 1])) == NULL) {
            perror("Cannot copy the sentence");
            exit(1);
        }
        hidePuzzle(currentPuzzle);

        while (!puzzleSolved) {
            playerTurn = true;

            while (playerTurn) {
                printf("Your turn: ");
                displayCurrentPlayer(players[currentPlayer]);

                wheelValue = spinWheel(wheel);
                occ = 0;

                switch (wheelValue) {
                 case -1:
                     printf("\nYou landed on Lose Turn... :(\n\n");
                     playerTurn = false;
                     break;
                 case 0:
                     printf("\nYou landed on Bankrupt... :(\n\n");
                     players[currentPlayer]->currentTurnMoney = 0;
                     playerTurn = false;
                     break;
                 case 1:
                     printf("\nYou landed on Extra Turn !\n\n");
                     currentPlayer = (--currentPlayer) % playersNumber;
                     playerTurn = false;
                     break;
                 default:
                     printf("\nYou landed on %d$ wedge\n", wheelValue);

                     // If the puzzle has only vowels left we allow player to buy one at his 1st turn
                     if (onlyVowelsLeft(puzzles[round-1], currentPuzzle))
                         players[currentPlayer]->canBuyVowel=true;

                     // If puzzles are the same then we directly ask for the puzzle guess
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
                             printf("'%c' is not a consonant!\n", guess);
                             correctCond = true;
                         }
                         flushInput();
                     }

                     // If puzzles are not the same, ask for a letter guess
                     if (occ != -1) {
                         if ((playerTurn = occ = getOccurrence(puzzles[round - 1], currentPuzzle, guess))) {
                             printf("Congratulations, '%c' is present %d time(s) in the puzzle\n", guess, occ);
                             addMoney(players[currentPlayer], isVowel(guess) ? ((occ * wheelValue) - 250) : (occ * wheelValue));
                             printf("Your new balance: %d$\n", players[currentPlayer]->currentTurnMoney);
                         }
                         else {
                             printf("'%c' is not contained in the puzzle\n", guess);
                             addMoney(players[currentPlayer], isVowel(guess) ? (- 250) : 0);
                         }
                     }
                     displayPuzzle(currentPuzzle);
                     players[currentPlayer]->canBuyVowel = true;

                     // If players find occurences then he can guess the puzzle
                     if (occ!=0) {

                         // If puzzles are not the same ask if want to solve
                         if (occ>=0) {
                             printf("\n\n");
                             do {
                                 printf("Do you want to guess the puzzle ? [Y/N] ");
                                 scanf(" %c", &guess);
                                 flushInput();
                             } while (guess != 'Y' && guess != 'N'); 
                         }

                         if (occ == -1 || guess == 'Y') {
                             printf("Enter your guess: ");                             
                             if ((puzzleGuess = strdup(my_gets(BUFFER_SIZE))) == NULL) {
                                 perror("Cannot copy the guess");
                                 exit(1);
                             }

                             if (stringCompare(puzzleGuess, puzzles[round - 1])) {
                                 addMoney(players[currentPlayer], occ==-1 ? (wheelValue) : 0);
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
                                 printf("I am afraid this is not the correct answer\n\n");
                             }
                             playerTurn = false;
                         }
                         else {
                             printf("OK, let's continue!\n");
                             displayPuzzle(currentPuzzle);
                         }
                     }
                     break;
                }               
            } 
            currentPlayer = (++currentPlayer) % playersNumber;
        }
        printf("\n-----END OF ROUND %d-----", round);
        endRound(players, playersNumber);
        wheel[23] += 500;
    }
    printf("\033[1;36m####################### GAME STANDING #######################\033[0m\n");
    endRound(players, playersNumber);
    printf("Thanks for playing !\n\n\n");

    free(puzzleGuess);
    free(currentPuzzle);
    freePuzzles(puzzles);
    freePlayers(players, playersNumber);

    puzzleGuess = NULL;
    currentPuzzle = NULL;
    puzzles = NULL;
    players = NULL;

    return 0;
}
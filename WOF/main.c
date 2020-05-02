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

    int round = 0;
    int wheelValue;
    int playersNumber;
    int currentPlayer;
    int wheel[24] = { -1, 0, 0, 1, 500, 500, 550, 550, 600, 600, 650, 650, 700, 700, 700, 750, 750, 800, 800, 850, 850, 900, 900, 2500 };
    bool puzzleSolved = false;

    displayLogo();
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

        currentPuzzle = _strdup(puzzles[round]);
        hidePuzzle(currentPuzzle);

        while (!puzzleSolved) {
            printf("Your turn: ");
            displayCurrentPlayer(players[currentPlayer]);

            wheelValue = spinWheel(wheel);

            switch (wheelValue) {
                case -1:
                    printf("You landed on Lose Turn... :(\n\n");
                break;
                case 0:
                    printf("You landed on Bankrupt... :(\n\n");
                    players[currentPlayer]->currentTurnMoney = 0;
                break;
                case 1:
                    printf("You landed on Extra Turn !\n\n");
                    currentPlayer = (--currentPlayer) % playersNumber;
                break;
                default:
                    printf("You landed on %d$ wedge\n", wheelValue);
                    
                    if (!players[currentPlayer]->hasPlayed) {
                        do {
                            printf("Enter a consonant: ");
                            scanf_s(" %c", &guess);
                            
                            if (isVowel(guess)) {
                                printf("%c is not a consonant, and you don't have enough money to buy a vowel!\n", guess);
                            }
                        } while (isVowel(guess));
                        int occ = getOccurrence(puzzles[round], currentPuzzle, guess);
                        if (occ == 0) {
                            printf("%c is not contained in the puzzle\n", guess);
                            addMoney(players[currentPlayer], (occ * wheelValue));
                            printf("Your new balance: %d$\n", players[currentPlayer]->currentTurnMoney);
                        }
                        else {
                            printf("Congratulations, %c is present %d times in the puzzle\n", guess, occ);
                            addMoney(players[currentPlayer], (occ * wheelValue));
                            printf("Your new balance: %d$\n", players[currentPlayer]->currentTurnMoney);
                        }
                        displayPuzzle(currentPuzzle);
                    }
                    //SECOND OR MORE TURN
                    else {
                        bool succTurn = false;
                        do {
                            printf("Enter a consonant or buy a vowel (-250$): ");
                            scanf_s(" %c", &guess);

                            if (isVowel(guess)) {
                                if (players[currentPlayer]->currentTurnMoney < 250){
                                    printf("You don't have enough money to buy a vowel\n");
                                }
                                else {
                                    int occ = getOccurrence(puzzles[round], currentPuzzle, guess);
                                    if (occ == 0) {
                                        printf("%c is not contained in the puzzle\n", guess);
                                        addMoney(players[currentPlayer], -250);
                                        printf("Your new balance: %d$\n\n", players[currentPlayer]->currentTurnMoney);
                                    }                                       
                                    else {
                                        printf("Congratulations, %c is present %d times in the puzzle\n", guess, occ);
                                        addMoney(players[currentPlayer], (occ * wheelValue) - 250);
                                        printf("Your new balance: %d$\n\n", players[currentPlayer]->currentTurnMoney);
                                    }  
                                    succTurn = true;
                                }
                            }
                            else {
                                int occ = getOccurrence(puzzles[round], currentPuzzle, guess);
                                if (occ == 0) {
                                    printf("%c is not contained in the puzzle\n", guess);
                                    addMoney(players[currentPlayer], (occ * wheelValue));
                                    printf("Your new balance: %d\n\n", players[currentPlayer]->currentTurnMoney);
                                }
                                else {
                                    printf("Congratulations, %c is present %d times inthe puzzle\n", guess, occ);
                                    addMoney(players[currentPlayer], (occ * wheelValue));
                                    printf("Your new balance: %d\n\n", players[currentPlayer]->currentTurnMoney);
                                }
                            }
                        } while (!succTurn);
                    }
                break;
            }
            currentPlayer = (++currentPlayer) % playersNumber;
        }
        round++;
    } while (round < 3);

    return 0;
}
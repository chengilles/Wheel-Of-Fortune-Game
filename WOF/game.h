#ifndef GAME_H
#define GAME_H
#include "io.h"
#include "player.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <stdbool.h>
#include <string.h>
//#include <ctype.h>

#define wheelInit { -1, 0, 0, 1, 500, 500, 550, 550, 600, 600, 650, 650, 700, 700, 700, 750, 750, 800, 800, 850, 850, 900, 900, 2500 }

// Selects a new puzzle, set money to 0, print winner.
void endRound(Player** players, int playersNumber);

// Displays current player name + his money.
void displayCurrentPlayer(Player* p);

// Displays current round.
void displayCurrentRound(int round);

// Adds money to player.
void addMoney(Player* p, int money);

// Displays the loading bar.
void loadingBar(int random);

// Returns occurrence of a character in the puzzle and reveal them if present.
int getOccurrence(char* puzzle, char* currentPuzzle, char c);

// Checks if a char is a vowel.
bool isVowel(char c);

// Returns a random number and takes the corresponding value in the array.
int spinWheel(int wheel[]);

// Hides the Puzzle by replacing each character with a dash '-'.
void hidePuzzle(char* currentPuzzle);

// Display the current Puzzle so you can see the status of the solving.
void displayPuzzle(char* currentPuzzle);

// Checks if there are only vowels left in the Puzzle
bool onlyVowelsLeft(char* puzzle, char* currentPuzzle);

//  Compare 2 strings in tolower
bool stringCompare(char* puzzle, char* guess);

#endif /* GAME_H */
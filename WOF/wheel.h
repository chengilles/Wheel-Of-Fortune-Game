#ifndef WHEEL_H
#define WHEEL_H
#include <stdbool.h>
#include <string.h>
#include "player.h"
#include "io.h"

// Compares input with current puzzle.
bool solvePuzzle(char* puzzle);

// Returns occurrence of a character in the puzzle and reveal them if present.
int getOccurrence(char *puzzle, char *currentPuzzle, char c);

// Adds money to the player if the character guess is correctly.
bool guessResult(int wheelValue, char *puzzle, char *currentPuzzle, char c);

// Checks if a char is a vowel.
bool isVowel(char c);

// Checks if the vowel is in the puzzle.
bool buyVowel(Player* p, char* puzzle, char* currentPuzzle, char c);

// Returns a random number and takes the corresponding value in the array.
int spinWheel(int* wheel);

// Hides the Puzzle by replacing each character with a dash '-'.
void hidePuzzle(char* currentPuzzle);

// Display the current Puzzle so you can see the status of the solving.
void displayPuzzle(char* currentPuzzle);

#endif /* WHEEL_H */


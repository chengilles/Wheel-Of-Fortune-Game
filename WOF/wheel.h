#ifndef WHEEL_H
#define WHEEL_H
#include <stdbool.h>

// Compares input with current puzzle.
bool solvePuzzle();

// Returns occurrence of a character in the puzzle and reveal them if present.
int getOccurrence(char *puzzle,char *currentPuzzle, int c);

// Adds money to the player if the character guess is correctly.
void guessResult(int wheelValue);

// Checks if a char is a vowel.
bool isVowel(char c);

// Checks if the vowel is in the puzzle.
bool buyVowel();

// Returns a random number and takes the corresponding value in the array.
int spinWheel();

#endif /* WHEEL_H */


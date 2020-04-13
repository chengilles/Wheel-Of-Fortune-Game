#ifndef WHEEL_H
#define WHEEL_H
#include <stdbool.h>

// Compares input with current puzzle.
bool solvePuzzle();

// Checks if a letter is present and returns number of occurrences.
int isPresent();

// Returns number of occurrences and reveal letters.
int revealLetter();

// Checks if a char is a vowel.
bool isVowel(char c);

// Checks if the vowel is in the puzzle.
bool buyVowel();

// Returns a random number and takes the corresponding value in the array.
int spinWheel();

#endif /* WHEEL_H */


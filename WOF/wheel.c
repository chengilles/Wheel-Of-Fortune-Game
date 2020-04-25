#include "wheel.h"

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
        return true;
    }
    return false;
}

int getOccurrence(char *puzzle, char *currentPuzzle, char c){
    int occurrence = 0;
    for(int i = 0; i < strlen(puzzle); i++){
        if(c == puzzle[i]){
            occurrence++;
            currentPuzzle[i] = c;
        }
    }
    return occurrence;
}

bool guessResult(int wheelValue, char *puzzle, char *currentPuzzle, char c){
    int occurrence = getOccurrence(puzzle, currentPuzzle, c);
    if(occurrence == 0)
        return false;
    return true;
}
 
bool buyVowel(Player* p, char* puzzle, char* currentPuzzle, char c) {
    if (p->currentTurnMoney >= 250) {
        p->currentTurnMoney -= 250;
        int occ = getOccurrence(puzzle, currentPuzzle, c);
        if (occ != 0) {
            printf("\nThere are %d '%c' in the puzzle!", occ, c);
            return true;
        }
        else {
            printf("\n%c is not in the puzzle.", c);
            return false;
        }
    }
    else {
        printf("\nYou don't have enough money to buy a vowel.");
        return false;
    }
}

bool solvePuzzle(char* puzzle) {
    char* guess = _strdup(my_gets(BUFFER_SIZE));
    if (strcmp(puzzle, guess) == 0)
        return true;
    return false;
}

int spinWheel(int* wheel) {
    //srand(time(NULL));
    int random = rand() % 24;
    return wheel + random;
}
#include "wheel.h"

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
        return true;
    }
    return false;
}

int getOccurrence(char *puzzle, char *currentPuzzle, char c){
    int occurrence = 0;
    for(int i = 0; i < strlen(puzzle); i++){
        if(currentPuzzle[i] == '-' && tolower(c) == tolower(puzzle[i])) {
            occurrence++;
            c = puzzle[i] > 95 ? tolower(c) : toupper(c);
            currentPuzzle[i] =c ;
        }
    }
    return occurrence;
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

int spinWheel(int wheel[]) {
    int random = rand() % 24;
    return wheel[random];
}


void hidePuzzle(char* currentPuzzle) {
    for(int i = 0; i < strlen(currentPuzzle); i++) {
        if(currentPuzzle[i] != ' ') {
            currentPuzzle[i] = '-';
        }
    }
    printf("\nThis will be the Puzzle you need to guess!  %s\n\n", currentPuzzle);
}

void displayPuzzle(char* currentPuzzle) {
    printf("\nCurrent Puzzle: %s\n\n", currentPuzzle);
}
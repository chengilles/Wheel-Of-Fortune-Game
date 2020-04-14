#include "wheel.h"

bool isVowel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
        return true;
    }
    return false;
}

int getOccurrence(char *puzzle,char *currentPuzzle, int c){
    int occurrence = 0;
    for(int i = 0; i < strlen(puzzle); i++){
        if(c == puzzle[i]){
            occurrence++;
            currentPuzzle[i] = c;
        }
    }
    return occurrence;
}

void guessResult(int wheelValue,char *puzzle,char *currentPuzzle, int c){
    if(getOccurrence(puzzle,currentPuzzle, c) == 0){
        printf("The letter %c is not contained in the Word\n", c);
    } else {
        printf("Good Job! The letter %c is present %d times in the Word. You will get %d * %d money.\nUpdate: %s", c, getOccurrence(puzzle,currentPuzzle,c),getOccurrence(puzzle,currentPuzzle,c), wheelValue, currentPuzzle);
    }
}
 
bool buyVowel(Player* p, char c) {
    if (p->currentTurnMoney >= 250) {
        p->currentTurnMoney -= 250;
        if (isPresent(c) != 0) {
            printf("\nThere are %d '%c' in the puzzle!", isPresent(c), c);
            return true;
        }
        else {
            printf("\n%c is not in the puzzle.");
            return false;
        }
    }
    else {
        printf("\nYou don't have enough money to buy a vowel.");
        return false;
    }
}

bool solvePuzzle(char* puzzle) {
    char* guess = strdup(my_gets(BUFFER_SIZE));
    if (strcmp(puzzle, guess) == 0)
        return true;
    return false;
}

int spinWheel(int* wheel) {
    //srand(time(NULL));
    int random = rand() % 24;
    return wheel + random;
}
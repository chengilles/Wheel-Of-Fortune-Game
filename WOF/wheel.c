#include "wheel.h"
#include <string.h>

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
 